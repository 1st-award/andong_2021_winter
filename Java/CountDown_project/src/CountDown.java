import java.util.Scanner;

public class CountDown {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num;
		
		do {
			System.out.print("���� ������ : ");
			num = sc.nextInt();
			if(num > 0)
				showCountDown(num);
		} while(num != -1);
		System.out.println("����Ǿ����ϴ�.");
	}
	
	public static void showCountDown(int _num) {
		for(int i = _num; i >= 0; --i) {
			System.out.printf("%d ", i);
		}
		System.out.println();
	}
}
