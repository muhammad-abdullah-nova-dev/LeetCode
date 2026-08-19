#define HASH_SIZE 262147

typedef struct {int row; int mask; int used;} Entry;

int hashRow(int row) {
    return (unsigned int)row % HASH_SIZE;
}

int getIndex(Entry* table, int row) {
    int idx = hashRow(row);

    while (table[idx].used && table[idx].row != row) {
        idx++;

        if (idx == HASH_SIZE) {
            idx = 0;
        }
    }

    if (!table[idx].used) {
        table[idx].used = 1;
        table[idx].row = row;
        table[idx].mask = 0;
    }

    return idx;
}

int maxNumberOfFamilies(
    int n,
    int** reservedSeats,
    int reservedSeatsSize,
    int* reservedSeatsColSize
) {
    Entry* table = calloc(HASH_SIZE, sizeof(Entry));

    int usedRows = 0;

    for (int i = 0; i < reservedSeatsSize; i++) {
        int row = reservedSeats[i][0];
        int seat = reservedSeats[i][1];

        if (seat == 1 || seat == 10) {
            continue;
        }

        int idx = getIndex(table, row);

        if (table[idx].mask == 0) {
            usedRows++;
        }

        if (seat >= 2 && seat <= 5) {
            table[idx].mask |= 1;
        }

        if (seat >= 4 && seat <= 7) {
            table[idx].mask |= 2;
        }

        if (seat >= 6 && seat <= 9) {
            table[idx].mask |= 4;
        }
    }

    int total = 2 * (n - usedRows);

    for (int i = 0; i < HASH_SIZE; i++) {
        if (!table[i].used) {
            continue;
        }

        int mask = table[i].mask;

        if (mask == 7) {
            continue;
        }

        total += 1;
    }

    free(table);

    return total;
}