import java.util.Scanner;

public class ShowInput {
	public static void main(String[] args) {
		int num;
		while(true) {
			num = getNum();
			getnum1();
			if(num > 0) {
				showNum(num);
			}
		}
	}
	
	public static int getNum() {
		Scanner sc = new Scanner(System.in);
		System.out.print("정숫값 : ");
		int num = sc.nextInt();
		// sc.close(); // java.util.NoSuchElementException
		return num;
	}
	
	public static int getnum1() {
		Scanner sc1 = new Scanner(System.in);
		int num = sc1.nextInt();
		return num;
	}
	
	public static void showNum(int _num) {
		System.out.println(_num + "가 입력되었습니다.");
	}
}
