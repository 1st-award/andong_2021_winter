import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Rectangle rect = new Rectangle();
		Scanner sc = new Scanner(System.in);
		
		System.out.print(">> ");
		rect.width = sc.nextInt();
		rect.height = sc.nextInt();
		
		System.out.println("�簢���� ������ " + rect.getArea());
	}
}