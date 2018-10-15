public class Main {

    static void plus(final int n, final int[][] a, final int[][] b, int[][] c, int mul){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                c[i][j] = a[i][j] + mul * b[i][j];
    }

    static void strassen(final int n, int[][] a, int[][] b, int[][] c){
        if(n == 1){
            c[0][0] = a[0][0] * b[0][0];
            return;
        }

        int[][] a11, a12, a21, a22;
        int[][] b11, b12, b21, b22;
        int[][] m1, m2, m3, m4, m5, m6, m7;

        int[][] cache1, cache2;

        a11 = new int[n/2][n/2]; a12 = new int[n/2][n/2];
        a21 = new int[n/2][n/2]; a22 = new int[n/2][n/2];

        b11 = new int[n/2][n/2]; b12 = new int[n/2][n/2];
        b21 = new int[n/2][n/2]; b22 = new int[n/2][n/2];

        m1 = new int[n/2][n/2]; m2 = new int[n/2][n/2];
        m3 = new int[n/2][n/2]; m4 = new int[n/2][n/2];
        m5 = new int[n/2][n/2]; m6 = new int[n/2][n/2];
        m7 = new int[n/2][n/2];

        cache1 = new int[n/2][n/2]; cache2 = new int[n/2][n/2];

        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n/2; j++){
                a11[i][j] = a[i][j]; a12[i][j] = a[i+n/2][j];
                a21[i][j] = a[i][j+n/2]; a22[i][j] = a[i+n/2][j+n/2];

                b11[i][j] = b[i][j]; b12[i][j] = b[i+n/2][j];
                b21[i][j] = b[i][j+n/2]; b22[i][j] = b[i+n/2][j+n/2];
            }
        }

        plus(n/2, a11, a22, cache1, 1); plus(n/2, b11, b22, cache2, 1);
        strassen(n/2, cache1, cache2, m1);

        plus(n/2, a21, a22, cache1, 1);
        strassen(n/2, cache1, b11, m2);

        plus(n/2, b12, b22, cache1, -1);
        strassen(n/2, a11, cache1, m3);

        plus(n/2, b21, b11, cache1, -1);
        strassen(n/2, a22, cache1, m4);

        plus(n/2, a11, a12, cache1, 1);
        strassen(n/2, cache1, b22, m5);

        plus(n/2, a21, a11, cache1, -1); plus(n/2, b11, b12, cache2, 1);
        strassen(n/2, cache1, cache2, m6);

        plus(n/2, a12, a22, cache1, -1); plus(n/2, b21, b22, cache2, 1);
        strassen(n/2, cache1, cache2, m7);

        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n/2; j++){
                c[i][j] = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
                c[i+n/2][j] = m3[i][j] + m5[i][j];
                c[i][j+n/2] = m2[i][j] + m4[i][j];
                c[i+n/2][j+n/2] = m1[i][j] - m2[i][j] + m3[i][j] + m6[i][j];
            }
        }
    }

    static void multiply(final int n, final int[][] a, final int[][] b, int[][] c){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    c[i][j] += a[i][k] * b[k][j];
    }

    public static void main(String[] args) {
        boolean result = true;
        int N = 4096;

        int[][] a = new int[N][N];
        int[][] b = new int[N][N];

        int[][] result_strassen = new int[N][N];
        int[][] result_normal = new int[N][N];

        double start_strassen, end_strassen,
                start_normal, end_normal;
        double diff_strassen, diff_normal;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                a[i][j] = i + j * N;
                b[i][j] = i == j ? 1 : 0;
            }
        }

        start_strassen = System.nanoTime();
        strassen(N, a, b, result_strassen);
        end_strassen = System.nanoTime();

        start_normal = System.nanoTime();
        multiply(N, a, b, result_normal);
        end_normal = System.nanoTime();

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                result = result && result_normal[i][j] == result_strassen[i][j];

        diff_normal = (end_normal - start_normal);
        diff_strassen = (end_strassen - start_strassen);

        System.out.println("IS OK? " + (result ? "YES" : "NO"));
        System.out.println("STRASSEN : "+ diff_strassen);
        System.out.println("NORMAL : " + diff_normal);
        System.out.println("IS STRASSEN BETTER THAN NORMAL? : "+
                (diff_normal > diff_strassen ? "TRUE" : "FALSE"));

    }
}
