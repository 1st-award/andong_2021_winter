public class ForeachEx {
	public static void main(String[] args) {
		int[] n = {1, 2 ,3 , 4, 5};
		String names[] = {"사과", "배", "배나나", "체리", "딸기", "포도"};
		
		int sum = 0;
		for(int k : n) {
			System.out.print(k + " ");
			sum += k;
		}
		System.out.println("합은 " + sum);
		
		showFruit(names);
	}
	
	public static void showFruit(String _arr[]) {
		for(String s : _arr)
			System.out.print(s + " ");
		System.out.println();
	}
}
