import java.util.Scanner;

public class CountDown {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num;
		
		do {
			System.out.print("양의 정수값 : ");
			num = sc.nextInt();
			if(num > 0)
				showCountDown(num);
		} while(num != -1);
		System.out.println("종료되었습니다.");
	}
	
	public static void showCountDown(int _num) {
		for(int i = _num; i >= 0; --i) {
			System.out.printf("%d ", i);
		}
		System.out.println();
	}
}
