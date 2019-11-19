#include <stdio.h>
#include "matriks.h"

void MakeMATRIKS (int NR, int NC, MATRIKS * M) {
    /* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NR x NC di "ujung kiri" memori */
    /* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
    NRowEff(*M) = NR;
    NColEff(*M) = NC;
}

/* *** Selektor *** */
#define NRowEff(M) (M).NRowEff
#define NColEff(M) (M).NColEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j) {
    /* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
    return ((i <= MinRow) && (i >= MaxRow) && (j <= MinCol) && (j >= MaxCol));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
idx GetFirstIdxRow (MATRIKS M) {
    /* Mengirimkan indeks baris terkecil M */
    return MinRow;
}

idx GetFirstIdxCol (MATRIKS M) {
    /* Mengirimkan indeks kolom terkecil M */
    return MinCol;
}

idx GetLastIdxRow (MATRIKS M) {
    /* Mengirimkan indeks baris terbesar M */
    return NRowEff(M);
}

idx GetLastIdxCol (MATRIKS M) {
    /* Mengirimkan indeks kolom terbesar M */
    return NColEff(M);
}

boolean IsIdxEff (MATRIKS M, idx i, idx j) {
    /* Mengirimkan true jika i, j adalah indeks efektif bagi M */
    return ((i <= NRowEff(M)) && (j <= NColEff(M)) && IsIdxValid(i,j));
}

ElTypeM GetElmtDiagonal (MATRIKS M, idx i) {
    /* Mengirimkan elemen M(i,i) */
    return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MOut) {
    /* Melakukan assignment MOut = MIn */

    /* Kamus Lokal */
    int i,j;

    /* Algoritma */
    NRowEff(*MOut) = NRowEff(MIn);
    NColEff(*MOut) = NColEff(MIn);
    for (i=1; i<=NRowEff(MIn); i++) {
        for (j=1; j<=NColEff(MIn); j++) {
            Elmt(*MOut,i,j) = Elmt(MIn,i,j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NR, int NC) {
    /* I.S. IsIdxValid(NR,NC) */ 
    /* F.S. M terdefinisi nilai elemen efektifnya, berukuran NR x NC */
    /* Proses: Melakukan MakeMATRIKS(M,NR,NC) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika NR = 3 dan NC = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10 
    */
    
    /* Kamus Lokal */
    int i,j,N;

    /* Algoritma */
    MakeMATRIKS(NR,NC,M);
    NRowEff(*M) = NR;
    NColEff(*M) = NC;
    for (i=GetFirstIdxRow(*M); i<=NR; i++) {
        for (j=GetFirstIdxCol(*M); j<=NC; j++) {
            scanf("%s",&N);
            Elmt(*M,i,j) = N;
        }
    }
}

void TulisMATRIKS (MATRIKS M) {
    /* I.S. M terdefinisi */
    /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
    dipisahkan sebuah spasi */
    /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */

    /* Kamus Lokal */
    int i,j;

    /* Algoritma */
    for (i=1; i<=NRowEff(M); i++) {
        for (j=1; j<=NColEff(M); j++) {
            if ((j==NColEff(M)) && (i!=NRowEff(M))) {
                printf(" %c |\n", Elmt(M,i,j));
            } else if ((j==NColEff(M)) && (i==NRowEff(M))) {
                printf(" %c |", Elmt(M,i,j));
            } else {
                printf("%c ", Elmt(M,i,j));
            }
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2) {
    /* Prekondisi : M1  berukuran sama dengan M2 */
    /* Mengirim hasil penjumlahan matriks: M1 + M2 */

    /* Kamus Lokal */
    int i,j;
    MATRIKS M3;

    /* Algoritma */
    NRowEff(M3) = NRowEff(M1);
    NColEff(M3) = NColEff(M1);
    for (i=1; i<=NRowEff(M1); i++) {
        for (j=1; j<=NColEff(M1); j++) {
            Elmt(M3,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
        }
    }
    return M3;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2) {
    /* Prekondisi : M berukuran sama dengan M */
    /* Mengirim hasil pengurangan matriks: salinan M1 - M2 */

    /* Kamus Lokal */
    int i,j;
    MATRIKS M3;

    /* Algoritma */
    NRowEff(M3) = NRowEff(M1);
    NColEff(M3) = NColEff(M1);
    for (i=1; i<=NRowEff(M1); i++) {
        for (j=1; j<=NColEff(M1); j++) {
            Elmt(M3,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
        }
    }
    return M3;
} 
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2) {
    /* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
    /* Mengirim hasil perkalian matriks: salinan M1 * M2 */

    /* Kamus Lokal */
    int i,j,k;
    MATRIKS M3;

    /* Algoritma */
    MakeMATRIKS(NRowEff(M1),NColEff(M2),&M3);
    for (i=1; i<=NRowEff(M3); i++) {
        for (j=1; j<=NColEff(M3); j++) {
            Elmt(M3,i,j) = 0;
            for (k=1; k<=NColEff(M1); k++) {
                Elmt(M3,i,j) = Elmt(M3,i,j) + (Elmt(M1,i,k) * Elmt(M2,k,j));
            }
        }
    }
    return M3;
}

MATRIKS KaliKons (MATRIKS M, ElTypeM X) {
    /* Mengirim hasil perkalian setiap elemen M dengan X */

    /* Kamus Lokal */
    int i,j;
    MATRIKS M1;

    /* Algoritma */
    NRowEff(M1) = NRowEff(M);
    NColEff(M1) = NColEff(M);
    for (i=1; i<=NRowEff(M); i++) {
        for (j=1; j<=NColEff(M); j++) {
            Elmt(M1,i,j) = X * Elmt(M,i,j);
        }
    }
    return M1;
}

void PKaliKons (MATRIKS * M, ElTypeM K) {
    /* I.S. M terdefinisi, K terdefinisi */
    /* F.S. Mengalikan setiap elemen M dengan K */

    /* Kamus Lokal */
    int i,j;

    /* Algoritma */
    for (i=1; i<=NRowEff(*M); i++) {
        for (j=1; j<=NColEff(*M); j++) {
            Elmt(*M,i,j) = K * Elmt(*M,i,j);
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQMatriks (MATRIKS M1, MATRIKS M2) {
    /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
    /* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
    /* Juga merupakan strong EQ karena GetFirstIdxRow(M1) = GetFirstIdxRow(M2) 
    dan GetLastIdxCol(M1) = GetLastIdxCol(M2) */

    /* Kamus Lokal */
    idx i,j;
    boolean EQElmt;

    /* Algoritma */
    if ((GetFirstIdxRow(M1) != GetFirstIdxRow(M2)) || (GetLastIdxRow(M1) != GetLastIdxRow(M2))) {
        return false;
    } else {
        EQElmt = true;
        i = GetFirstIdxRow(M1);
        while (EQElmt && i<=GetLastIdxRow(M1)) {
            j = GetFirstIdxCol(M1);
            while (EQElmt && j<=GetLastIdxCol(M1)) {
                if (Elmt(M1,i,j) != Elmt(M2,i,j)) {
                    EQElmt = false;
                } else {
                    j++;
                }
            }
            if (EQElmt) {
                i++;
            }
        }
        return EQElmt;
    }
}

boolean NEQMatriks (MATRIKS M1, MATRIKS M2) {
    /* Mengirimkan true jika M1 tidak sama dengan M2 */

    /* Kamus Lokal */
    boolean found;
    int i,j;

    /* Algoritma */
    i = 1;
    j = 1;
    found = false;
    if (NBElmtMatriks(M1) != NBElmtMatriks(M2)) {
        return true;
    } else {
        while ((i<=NRowEff(M1)) && (!found)) {
            while ((j<=NColEff(M1)) && (!found)) {
                if (Elmt(M1,i,j) != Elmt(M2,i,j)) {
                    found = true;
                }
                j++;
            }
            i++;
        }
    }
    
    if (found) {
        return true;
    } else {
        return false;
    }
}

boolean EQSize (MATRIKS M1, MATRIKS M2) {
    /* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
    /* yaitu GetNRowEff(M1) = GetNRowEff (M2) dan GetNColEff (M1) = GetNColEff (M2) */
    return ((NRowEff(M1) == NRowEff(M2)) && (NColEff(M1) == NColEff(M2)));
}

/* ********** Operasi lain ********** */
int NBElmtMatriks (MATRIKS M) {
    /* Mengirimkan banyaknya elemen M */
    return NRowEff(M) * NColEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M) {
    /* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
    return ((NRowEff(M) == NColEff(M)) && (NBElmtMatriks(M) > 0));
}

boolean IsSimetri (MATRIKS M) {
    /* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
    dan untuk setiap elemen M, M(i,j)=M(j,i) */

    /* Kamus Lokal */
    boolean found;
    int i,j;

    /* Algoritma */
    i = 1;
    j = 1;
    found = false;
    while ((!found) && (i<=NRowEff(M))) {
        while ((!found) && (j<=NColEff(M))) {
            if (Elmt(M,i,j) != (Elmt(M,j,i))) {
                found = true;
            }
            j++;
        }
        i++;
    }

    if (found) {
        return false;
    }
    else {
        return true;
    }
}

boolean IsSatuan (MATRIKS M) {
    /* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
    setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */

    /* Kamus Lokal */
    int i,j;
    boolean found;

    /* Algoritma */
    i = 1;
    j = 1;
    found = false;

    while ((!found) && (i<=NRowEff(M))) {
        while ((!found) && (j<=NColEff(M))) {
            if (Elmt(M,i,i) != 1) {
                found = true;
            }
            if ((Elmt(M,i,j) != 0) && (j != i)) {
                found = true;
            }
            j++;
        }
        i++;
    }
    
    if (found) {
        return false;
    } else {
        return true;
    }
}

boolean IsSparse (MATRIKS M) {
    /* Mengirimkan true jika M adalah matriks sparse: matriks �jarang� dengan definisi: 
    hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 

    /* Kamus Lokal */
    int thres, count, i, j;

    /* Algoritma */
    count = 0;
    thres = NBElmtMatriks(M) / 20;
    for (i=1; i<=NRowEff(M); i++) {
        for (j=1; j<=NColEff(M); j++) {
            if (Elmt(M,i,j) == 0) {
                count++;
            }
        }
    }
    if (count > thres) {
        return true;
    } else {
        return false;
    }
}

MATRIKS Inverse1 (MATRIKS M) {
    /* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
    
    /* Kamus Lokal */
    int i,j;
    MATRIKS A;

    /* Algoritma */
    NRowEff(A) = NRowEff(M);
    NColEff(A) = NColEff(M);
    for (i=1; i<=NRowEff(M); i++) {
        for (j=1; j<=NColEff(M); j++) {
            Elmt(A,i,j) = Elmt(M,i,j) * -1;
        }
    }
    return A;
}

float Determinan (MATRIKS M);
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
void PInverse1 (MATRIKS * M) {
    /* I.S. M terdefinisi */
    /* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    
    /* Kamus Lokal */
    int i,j;

    /* Algoritma */
    for (i=1; i<=NRowEff(*M); i++) {
        for (j=1; j<=NColEff(*M); j++) {
            Elmt(*M,i,j) = Elmt(*M,i,j) * -1;
        }
    }
}

void Transpose (MATRIKS * M) {
    /* I.S. M terdefinisi dan IsBujursangkar(M) */
    /* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */

    /* Kamus Lokal */
    int i,j;
    MATRIKS A;

    /* Algoritma */
    NRowEff(A) = NRowEff(*M);
    NColEff(A) = NColEff(*M);
    for (i=1; i<=NRowEff(*M); i++) {
        for (j=1; j<=NColEff(*M); j++) {
            Elmt(A,i,j) = Elmt(*M,j,i);
        }
    }
    *M = A;
}