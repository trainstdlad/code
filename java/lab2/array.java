import java.io.*;
import java.util.Random;
public class java_lab{
    private static int k = 5; //количество элементов a
    private static int m1 = 5; //количество строк b
    private static int m2 = 4; //количество столбцов b
    private static int n = 3; //количество одномерных массивов c
    public static void print_1dim_array(int[] arr){
        for (int i = 0; i < k; i++)
            System.out.format("%" + "4d", arr[i]);
        System.out.println();
    }
    public static void print_2dim_array(int[][] arr){
        for(int i = 0; i < arr.length; i++){
            for(int j = 0; j < arr[i].length; j++)
                System.out.format("%"+"15d", arr[i][j]);
            System.out.println();
        }
    }
    public static int[] fill_1dim(){
        int[] arr = new int[k];
        Random rnd = new Random();
        for (int i = 0; i < arr.length; i++)
            arr[i] = (rnd.nextInt(65536) - 32768) % 7;
        return arr;
    }
    public static int[][] fill_2dim(int[] arr2){
        int[][] arr = new int[m1][m2];
        for(int i = 0; i < m1; i++)
            for(int j = 0; j < m2; j++)
                arr[i][j] = arr2[j] >>> i;
        return arr;
    }
    public static int[][] fill_2dim_irregular(int[][] arr2){
        Random rnd = new Random();
        int[][] arr = new int[n][];
        for(int i = 0; i < n; i++){
            int row_length = (1 + rnd.nextInt(4));
            int[] row = new int[row_length];
            for(int j = 0; j < row.length; j++)
                row[j] = i + j - column_least_element(arr2, j);
            arr[i] = row;
        }
        return arr;
    }
    public static int least_element(int[] arr){
        int min = arr[0];
        for(int i = 0; i < arr.length; i++)
            if(arr[i] < min)
                min = arr[i];
        return min;
    }
    public static int column_least_element(int[][] arr, int column){
        int min = arr[0][column];
        for(int i = 1; i < m1; i++)
            if(arr[i][column] < min)
                min = arr[i][column];
        return min;
    }
    public static void main(String[] args) throws Exception{
        int[] a = fill_1dim();
        System.out.print("a = ");
        print_1dim_array(a);
        int min = least_element(a);
        System.out.println("Least element of a = " + min);
        int[][] b = fill_2dim(a);
        System.out.println("Array b:");
        print_2dim_array(b);
        int[][] c = fill_2dim_irregular(b);
        System.out.println("Array c:");
        print_2dim_array(c);
    }
}
