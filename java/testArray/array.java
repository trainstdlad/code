//Array max element


import java.io.*;
import java.util.*;

public class array{
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<Integer> list = new ArrayList<Integer>();
		int max;
		for(int i = 0; i < 10; i++){
			int numb = Integer.parseInt(reader.readLine());
			list.add(numb);
		}

		System.out.println();

		max = list.get(0);

		for(int i = 0; i < list.size(); i++){
			if(list.get(i) > max){
				max = list.get(i);
			}
		}				

		System.out.println(max);

		System.out.println();

		for(int i = 0; i < list.size(); i++){
			System.out.println(list.get(i));
		}
	}
}