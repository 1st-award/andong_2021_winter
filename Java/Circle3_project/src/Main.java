public class Main {
	public static void main(String[] args) {
		Circle ob1 = new Circle(1);
		Circle ob2 = new Circle(2);
		Circle ob3 = new Circle(3);
		System.out.println(ob1.raidus);
		System.out.println(ob2.raidus);
		System.out.println(ob3.raidus);
		
		ob1.set(4);
		ob2.set(5);
		ob3.set(6);
		System.out.println(ob1.raidus);
		System.out.println(ob2.raidus);
		System.out.println(ob3.raidus);
	}
}
