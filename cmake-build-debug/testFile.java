class lol {

public static int func(int a, int b) {
    return a * b;
}

public static void main(String[] args) {
    System.out.println(args[0]);
	//int a = Integer.parseInt(args[0]);
	int a = 1;
	while(a < 10) {
	    a = func(a, 2);
        System.out.println(a);
	}

}




}
