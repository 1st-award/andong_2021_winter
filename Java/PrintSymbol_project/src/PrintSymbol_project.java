import java.util.Scanner;

public class PrintSymbol_project {
	public static void main(String[] args) {
		int length;
		
		while(true) {
			length = getLength();
			showSymbol(length);
		}
	}
	
	public static int getLength() {
		Scanner sc = new Scanner(System.in);
		System.out.print("ют╥б : ");
		int num = sc.nextInt();
		return num;
	}
	
	public static void showSymbol(int _length) {
		System.out.println();
		for(int i = 0; i<_length; ++i) {
			if(i % 2 == 0)
				System.out.print("*");
			else
				System.out.print("+");
		}
		System.out.println("\n");
	}
}
