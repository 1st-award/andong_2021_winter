import java.util.Scanner;

public class PositiveAndNegative {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(true) {
			System.out.print("���� �� : ");
			System.out.println(isPorN(sc.nextInt()));
		}
	}
	
	public static String isPorN(int _number) {
		if(_number > 0)
			return "���";
		else if(_number < 0)
			return "����";
		return "0";
	}
}
