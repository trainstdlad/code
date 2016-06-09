/**
 * Created by train_std on 09.06.16.
 */

import java.io.*;

public class test {
    public static void main(String[] args) throws Exception
    {
        int a, b;
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the number for summ");
        a = Integer.parseInt(reader.readLine());
        b = Integer.parseInt(reader.readLine());
        summa(a, b);
    }

    public static void summa(int a, int b){
        System.out.println(a + b);
    }
}
