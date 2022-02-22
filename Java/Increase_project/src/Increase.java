import java.util.Scanner;

public class Increase {
	public static void main(String[] args) {
		int num = setNum();
		showIncreaseNum(num);
	}
	
	public static int setNum() {
		Scanner sc = new Scanner(System.in);
		System.out.print("양의 정수값 : ");
		int num = sc.nextInt();
		sc.close();
		return num;
	}
	
	public static void showIncreaseNum(int num) {
		for(int i=0; i<=5; ++i)
			System.out.print(i + " ");
	}
}
