
import java.io.*;

public class min{
	public static void main(String[] args) throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		double x, y = 0;
		x = Double.parseDouble(reader.readLine());
		if(x <= 0){
			y = Math.abs(x);
			System.out.println("Number" + " " + y);

		}
		if(x > 0){
			for(int i = 1; i <= 3; i++){
				y = y + 1./(Math.pow(x,i));
				System.out.println(y);
			}
			System.out.println();
			System.out.println(y);
		}
	}
}
