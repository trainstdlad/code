import java.io.*;

public class min {
    public static void main(String[] args) throws Exception
    {
        int a, b, c;
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the number for summ");
        a = Integer.parseInt(reader.readLine());
        b = Integer.parseInt(reader.readLine());
        c = Integer.parseInt(reader.readLine());
        minimum(a, b, c);
    }

    public static void minimum(int a, int b, int c){
        int min;
        if(a > b && a > c){
            if(b > c){
                min = c;
                System.out.println("Min element" + " " + min);
            }
            else
                System.out.println("Min element" + " " + b);
        }

        if(b > a && b > c){
            if(a > c){
                min = c;
                System.out.println("Min element" + " " + min);
            }
            else
                System.out.println("Min element" + " " + a);
        }

        if(c > a && c > b){
            if(a > b){
                min = b;
                System.out.println("Min element" + " " + min);
            }
            else
                System.out.println("Min element" + " " + a);
        }
    }
}
