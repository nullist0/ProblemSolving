public class Main_NonePartition {

    static double[][] times = new double[2][1025];

    static int threshold;

    static int[][] matrix_add(int[][] a, int[][] b){
        int n = a.length;
        int[][] c = new int[n][n];

        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j++){
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        return c;
    }

    static int[][] matrix_subtract(int[][] a, int[][] b){
        int n = a.length;
        int[][] c = new int[n][n];

        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j++){
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        return c;
    }

    static void strassen(final int n, int[][] a, int[][] b, int[][] c){
        if(n == 1) {
            c[0][0] = a[0][0] * b[0][0];
            //multiply(n, a, b, c);
            return;
        }
        final int size = n/2;
        int[][] m1 = new int[size][size], m2 = new int[size][size],
                m3 = new int[size][size], m4 = new int[size][size],
                m5 = new int[size][size], m6 = new int[size][size],
                m7 = new int[size][size];

        int[][] temp1 = new int[size][size];
        int[][] temp2 = new int[size][size];
        for(int i = 0; i < size; i ++){
            for(int j = 0; j < size; j++){
                temp1[i][j] = a[i][j] + a[i+size][j+size];
                temp2[i][j] = b[i][j] + b[i+size][j+size];
            }
        }
        strassen(size, temp1, temp2, m1);

        for(int i = 0; i < size; i ++){
            for(int j = 0; j < size; j++){
                temp1[i][j] = a[i+size][j] + a[i+size][j+size];
                temp2[i][j] = b[i][j];
            }
        }
        strassen(size, temp1, temp2, m2);

        for(int i = 0; i < size; i ++){
            for(int j = 0; j < size; j++){
                temp1[i][j] = a[i][j];
                temp2[i][j] = b[i][j+size] - b[i+size][j+size];
            }
        }
        strassen(size, temp1, temp2, m3);


        for(int i = 0; i < size; i ++){
            for(int j = 0; j < size; j++){
                temp1[i][j] = a[i+size][j+size];
                temp2[i][j] = b[i+size][j] - b[i][j];
            }
        }
        strassen(size, temp1, temp2, m4);

        for(int i = 0; i < size; i ++){
            for(int j = 0; j < size; j++){
                temp1[i][j] = a[i][j] + a[i][j+size];
                temp2[i][j] = b[i+size][j+size];
            }
        }
        strassen(size, temp1, temp2, m5);

        for(int i = 0; i < size; i ++){
            for(int j = 0; j < size; j++){
                temp1[i][j] = a[i+size][j] - a[i][j];
                temp2[i][j] = b[i][j] + b[i][j+size];
            }
        }
        strassen(size, temp1, temp2, m6);

        for(int i = 0; i < size; i ++){
            for(int j = 0; j < size; j++){
                temp1[i][j] = a[i][j+size] - a[i+size][j+size];
                temp2[i][j] = b[i+size][j] + b[i+size][j+size];
            }
        }
        strassen(size, temp1, temp2, m7);

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                c[i][j] = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
                c[i][j + size] = m3[i][j] + m5[i][j];
                c[i + size][j] = m2[i][j] + m4[i][j];
                c[i+size][j+size] = m1[i][j] - m2[i][j] + m3[i][j] + m6[i][j];
            }
        }

        m1 = null;
        m2 = null;
        m3 = null;
        m4 = null;
        m5 = null;
        m6 = null;
        m7 = null;
        temp1 = null;
        temp2 = null;
    }

    static void multiply(final int n, final int[][] a, final int[][] b, int[][] c){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    c[i][j] += a[i][k] * b[k][j];
    }

    static double evaluateStrassen(int N){

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

        start_strassen = System.currentTimeMillis();
        strassen(N, a, b, result_strassen);
        end_strassen = System.currentTimeMillis();

        boolean result = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                result = result && a[i][j] == result_strassen[i][j];
            }
        }

        diff_strassen = (end_strassen - start_strassen);

        System.out.println("RESULT : " + result);
        System.out.println("N : " + N);// + ", Threshold : " + K);
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
        double n, s;
        for(int i = 1; ; i = i * 2){
            //for(int j = 1; j <= 1024; j = j * 2) {
                n = evaluateNormal(i);
                System.out.println();
                s = evaluateStrassen(i);
                System.out.println();
                if(s < n && i != 1){
                    System.out.println("Found threshold");
                    break;
                }
            //}
        }
    }
}
