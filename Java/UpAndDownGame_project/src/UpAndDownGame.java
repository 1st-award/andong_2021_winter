import java.util.Scanner;

public class UpAndDownGame {
	public static void main(String[] args) {
		int answer = setAnswer();
		int select;
		Scanner sc = new Scanner(System.in);
		
		do {
			System.out.print("������ : ");
			select = sc.nextInt();
			System.out.println(isAnswer(select, answer));
			
		} while(select != answer);
	}
	
	public static int setAnswer() {
		Scanner sc = new Scanner(System.in);
		System.out.print("���� ���� : ");
		return sc.nextInt();
	}
	
	public static String isAnswer(int _select, int _answer) {
		if(_select < _answer)
			return "UP";
		else if(_select > _answer)
			return "DOWN";
		else
			return "����!";
	}
}
