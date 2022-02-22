import java.util.Scanner;

public class FindDecimal {
	static boolean isDecimal(int _num) {
		for(int i = 2; i<_num; ++i) {
			if(_num%i==0)
				return false;
		}
		return true;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			System.out.print("정숫값 : ");
			int num = sc.nextInt();
			if(num == -1) {
				System.out.println("프로그램이 종료되었습니다.");
				break;
			}
			if(isDecimal(num))
				System.out.println("소수입니다.");
			else
				System.out.println("소수가 아닙니다.");
		}
	}
}
