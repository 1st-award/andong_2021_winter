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
			System.out.print("������ : ");
			int num = sc.nextInt();
			if(num == -1) {
				System.out.println("���α׷��� ����Ǿ����ϴ�.");
				break;
			}
			if(isDecimal(num))
				System.out.println("�Ҽ��Դϴ�.");
			else
				System.out.println("�Ҽ��� �ƴմϴ�.");
		}
	}
}
