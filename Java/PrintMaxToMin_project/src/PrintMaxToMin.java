import java.util.Scanner;

public class PrintMaxToMin {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = setNum('A');
		int b = setNum('B');
		showMaxToMin(a, b);
	}
	
	public static int setNum(char _chr) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Á¤¼ö " + _chr + " : ");
		return sc.nextInt();
	}
	
	public static void showMaxToMin(int _max, int _min) {
		for(int i=_min; i <= _max; ++i) {
			System.out.printf("%d ", i);
		}
	}
}
