#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
    unsigned int first;
    unsigned int second;
} EDGE;

void connect(EDGE *edges, unsigned int first, unsigned int second, unsigned int *pos) {
    edges[*pos].first = first;
    edges[*pos].second = second;
    (*pos)++;
}

unsigned int vertexcover(const EDGE *edges, unsigned int size, unsigned int order, unsigned int **cover) {
    unsigned int uncovsize = size;
    unsigned int covsize = 0;
    unsigned int *covered = calloc(size, sizeof(unsigned int));
    *cover = calloc(order, sizeof(unsigned int));
    if (covered == NULL || cover == NULL) {
        free(covered);
        free(*cover);
        *cover = NULL;
        return 0;
    }
    while (uncovsize > 0) {
        unsigned int e, v;
        for (e = 0; e < size && covered[e] == 1; e++);
        v = edges[e].first;
        (*cover)[v] = 1;
        covsize++;
        for (e = 0; e < size; e++) {
            if (!covered[e] && (edges[e].first == v || edges[e].second == v)) {
                covered[e] = 1;
                uncovsize--;
            }
        }
    }
    free(covered);
    return covsize;
}

void main() {
    const unsigned int size = 4;
    const unsigned int order = 5;
    EDGE *edges = malloc(size * sizeof(EDGE));
    unsigned int i = 0;
    connect(edges, 0, 1, &i);
    connect(edges, 0, 2, &i);
    connect(edges, 0, 3, &i);
    connect(edges, 1, 4, &i);
    unsigned int *cover;
    unsigned int c = vertexcover(edges, size, order, &cover);
    printf("Cover size: %u\n", c);
    printf("The vertices in the cover are: ");
    for (i = 0; i < order; i++) {
        if (cover[i]) {
            printf("%u ", i);
        }
    }
    putchar('\n');
    free(edges);
    free(cover);
}
