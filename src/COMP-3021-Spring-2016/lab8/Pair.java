public class Pair {
	private int key;
	private int value;

	public Pair(int theKey, int theValue) {
		key = theKey;
		value = theValue;
	}

	public void setKey(int theKey) {
		key = theKey;
	}

	public void setValue(int theValue) {
		value = theValue;
	}

	public int getKey() {
		return key;
	}

	public int getValue() {
		return value;
	}

	public void instancePrint() {
		System.out.println("instancePrint -- key: " + key + ", value: " + value);
	}


	public static void staticPrint(int theKey, int theValue) {
		System.out.println("staticPrint -- key: " + theKey + ", value: " + theValue);
	}

	public static void main(String []args) {
		//Pair 0
		int key0 = 123;
		int value0 = 456;

		//TO DO: modify Pair 0's initialization to match the generic class and method you just implemented

		Pair pair0 = new Pair(key0, value0);
		pair0.instancePrint();
		Pair.staticPrint(key0, value0);

		//Pair 1
		String key1 = "Apple";
		double value1 = 2.4;

		//TO DO: construct Pair 1, and print out

		//Pair 2
		int key2 = 4200;
		java.util.Date value2 = new java.util.Date();

		//TO DO: construct Pair 2, and print out

	}
}
