import java.util.Scanner;

public class BreakExample {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("exit�� �Է��ϸ� �����մϴ�.");
		while(true) {
			System.out.print(">>");
			String text = sc.nextLine();
			if(text.contentEquals("exit")) {
				break;
			}
		}
		System.out.println("����");
	}
}
