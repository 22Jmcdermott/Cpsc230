

public class MyThread extends Thread{
private int startIndex;
private int endIndex;
private long startTime;
private long endTime;
private int[] array;
private int sum;

	public MyThread(int startIndex, int endIndex, int[] array) {
	this.startIndex = startIndex;
	this.endIndex = endIndex;
	this.array = array;
}
	public void run() {
		startTime = System.nanoTime();
		for(int i =startIndex; i < endIndex; i++) {
			sum+=array[i];
		}
		endTime = System.nanoTime();
		
	}
protected int getSum() {
	return sum;
}
protected long getTime() {
	long time = endTime - startTime;
	return time;
}
}
