public class Main {

    static double[][] times = new double[2][1025];

    static int threshold;

    static void strassen(final int n, int[][] a, int[][] b, int[][] c){
        if(n <= threshold) {
            multiply(n, a, b, c);
            return;
        }

        int[][] a11, a12, a21, a22;
        int[][] b11, b12, b21, b22;
        int[][] m1, m2, m3, m4, m5, m6, m7;

        int[][] mt11, mt12, mt21, mt32, mt42, mt51, mt61, mt62, mt71, mt72;

        double start, end;

        a11 = new int[n/2][n/2]; a12 = new int[n/2][n/2];
        a21 = new int[n/2][n/2]; a22 = new int[n/2][n/2];

        b11 = new int[n/2][n/2]; b12 = new int[n/2][n/2];
        b21 = new int[n/2][n/2]; b22 = new int[n/2][n/2];

        m1 = new int[n/2][n/2]; m2 = new int[n/2][n/2];
        m3 = new int[n/2][n/2]; m4 = new int[n/2][n/2];
        m5 = new int[n/2][n/2]; m6 = new int[n/2][n/2];
        m7 = new int[n/2][n/2];

        mt11 = new int[n/2][n/2]; mt12 = new int[n/2][n/2];
        mt21 = new int[n/2][n/2];
        mt32 = new int[n/2][n/2];
        mt42 = new int[n/2][n/2];
        mt51 = new int[n/2][n/2];
        mt61 = new int[n/2][n/2]; mt62 = new int[n/2][n/2];
        mt71 = new int[n/2][n/2]; mt72 = new int[n/2][n/2];

        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n/2; j++){
                a11[i][j] = a[i][j]; a12[i][j] = a[i+n/2][j];
                a21[i][j] = a[i][j+n/2]; a22[i][j] = a[i+n/2][j+n/2];

                b11[i][j] = b[i][j]; b12[i][j] = b[i+n/2][j];
                b21[i][j] = b[i][j+n/2]; b22[i][j] = b[i+n/2][j+n/2];

                mt11[i][j] = a11[i][j] + a22[i][j]; mt12[i][j] = b11[i][j] + b22[i][j];
                mt12[i][j] = a21[i][j] + a22[i][j];
                mt32[i][j] = b12[i][j] - b22[i][j];
                mt42[i][j] = b21[i][j] - b11[i][j];
                mt51[i][j] = a11[i][j] + a12[i][j];
                mt61[i][j] = a21[i][j] - a11[i][j]; mt62[i][j] = b11[i][j] + b12[i][j];
                mt71[i][j] = a12[i][j] - a22[i][j]; mt72[i][j] = b21[i][j] + b22[i][j];
            }
        }

        strassen(n/2, mt11, mt12, m1);
        strassen(n/2, mt21, b11, m2);
        strassen(n/2, a11, mt32, m3);
        strassen(n/2, a22, mt42, m4);
        strassen(n/2, mt51, b22, m5);
        strassen(n/2, mt61, mt62, m6);
        strassen(n/2, mt71, mt72, m7);

        start = System.currentTimeMillis();
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n/2; j++){
                c[i][j] = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
                c[i+n/2][j] = m3[i][j] + m5[i][j];
                c[i][j+n/2] = m2[i][j] + m4[i][j];
                c[i+n/2][j+n/2] = m1[i][j] - m2[i][j] + m3[i][j] + m6[i][j];
            }
        }
        end = System.currentTimeMillis();

        times[0][n]++;
        times[1][n] += end - start;
    }

    static void multiply(final int n, final int[][] a, final int[][] b, int[][] c){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    c[i][j] += a[i][k] * b[k][j];
    }

    static double evaluateStrassen(int N, int K){

        int[][] a = new int[N][N];
        int[][] b = new int[N][N];

        int[][] result_strassen = new int[N][N];

        double start_strassen = 0, end_strassen = 0;
        double diff_strassen = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                a[i][j] = i + j * N;
                b[i][j] = i == j ? 1 : 0;
            }
        }

        threshold = K;
        start_strassen = System.currentTimeMillis();
        strassen(N, a, b, result_strassen);
        end_strassen = System.currentTimeMillis();

        diff_strassen = (end_strassen - start_strassen);

        System.out.println("N : " + N + ", Threshold : " + K);
        System.out.println("STRASSEN : "+ diff_strassen);
        return diff_strassen;//diff_normal > diff_strassen;
    }

    static double evaluateNormal(int N){

        int[][] a = new int[N][N];
        int[][] b = new int[N][N];

        int[][] result_normal = new int[N][N];

        double start_normal = 0, end_normal = 0;
        double diff_normal = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                a[i][j] = i + j * N;
                b[i][j] = i == j ? 1 : 0;
            }
        }

        start_normal = System.currentTimeMillis();
        multiply(N, a, b, result_normal);
        end_normal = System.currentTimeMillis();

        diff_normal = (end_normal - start_normal);

        System.out.println("N : " + N);
        System.out.println("NORMAL : " + diff_normal);
        return diff_normal;//diff_normal > diff_strassen;
    }

    public static void main(String[] args) {

        for(int i = 1; i <= 1024; i = i * 2){
            for(int j = 1; j <= 1024; j = j * 2) {
                //evaluateNormal(i);
                evaluateStrassen(i, j);
            }
        }
    }
}
