#include <mystdlib.h>
#include <mysyscall.h>

/* alloue et commit physiquement */
void *mmap_alloc(size_t user_size) {
    if (user_size == 0) return 0;

    unsigned long total = (unsigned long)user_size + sizeof(struct mmap_header);
    unsigned long map_size = PAGE_ALIGN_UP(total);

    void *p = sys_mmap(0, map_size, 3 /*PROT_READ|PROT_WRITE*/, 0x22 /*MAP_PRIVATE|MAP_ANONYMOUS*/, -1, 0);
    if (p == (void*)-1 || p == (void*)0) return 0;

    // store header at beginning
    struct mmap_header *h = (struct mmap_header*)p;
    h->total_size = map_size;
    h->user_size = user_size;

    // pointer à retourner à l'utilisateur
    char *user_ptr = (char*)p + sizeof(struct mmap_header);

    // toucher chaque page pour forcer l'allocation physique
    // commencer à la page contenant user_ptr (ou mieux : commencer à p + sizeof(header) aligné)
    unsigned long offset = ((unsigned long)user_ptr) & (PAGE_SIZE - 1);
    char *start = (char*)user_ptr - offset; // page-aligned start <= user_ptr

    unsigned long pages = (map_size + ((unsigned long)p - (unsigned long)start)) / PAGE_SIZE;
    // plus simple: parcourir de p (début du mapping) en pas de PAGE_SIZE jusqu'à map_size
    char *q = (char*)p;
    unsigned long i;
    for (i = 0; i < map_size; i += PAGE_SIZE) {
        // écrit 0 sur chaque page pour forcer la fault
        q[i] = 0;
    }

    return (void*)user_ptr;
}

/* libère le mapping */
void mmap_free(void *user_ptr) {
    if (!user_ptr) return;
    struct mmap_header *h = (struct mmap_header*)((char*)user_ptr - sizeof(struct mmap_header));
    unsigned long map_size = h->total_size;
    void *base = (void*)h;
    sys_munmap(base, map_size);
}

/* Optionnel : wrappers malloc/free utilisant mmap_alloc/mmap_free */
void *malloc(size_t s) { return mmap_alloc(s); }
void free(void *p) { mmap_free(p); }