public class ForeachEx {
	public static void main(String[] args) {
		int[] n = {1, 2 ,3 , 4, 5};
		String names[] = {"���", "��", "�質��", "ü��", "����", "����"};
		
		int sum = 0;
		for(int k : n) {
			System.out.print(k + " ");
			sum += k;
		}
		System.out.println("���� " + sum);
		
		showFruit(names);
	}
	
	public static void showFruit(String _arr[]) {
		for(String s : _arr)
			System.out.print(s + " ");
		System.out.println();
	}
}
