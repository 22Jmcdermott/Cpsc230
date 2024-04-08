import java.util.ArrayList;
import java.util.Random;

public class MultiThreadingLab1 {

	public static void main(String[] args) {
		
		
		int numThreads = 10;
		int arraySize = 10;
		int[] array = new int[arraySize];
		Random random = new Random();
		MultiThreadingLab1 m = new MultiThreadingLab1();
		for(int i=0; i<array.length; i++) {
			
			array[i] = random.nextInt(101);
		}
	
	
	
	
	ArrayList<MyThread> tarray = new ArrayList<>();
	int indexPerThread = arraySize / numThreads;
	int remainingIndexes = arraySize % numThreads;
	int startIndex = 0;
	int sum =0;
	for(int threadNum = 0; threadNum < numThreads; threadNum++) {
		int endIndex = startIndex + indexPerThread;
		if(threadNum<remainingIndexes) {
			endIndex++;
		}
		MyThread thread = new MyThread(startIndex, endIndex, array);
		tarray.add(thread);
		startIndex = endIndex;
	}
	for(MyThread thread : tarray) {
		thread.run();
	}
	long worstRunTime = 0;
	for(MyThread thread : tarray) {
		try {
			thread.join();
			sum+=thread.getSum();
			if(thread.getTime()>worstRunTime) {
				worstRunTime = thread.getTime();
				
			}
		}catch(InterruptedException e) {
			e.printStackTrace();
		}
	}
	for(MyThread thread : tarray) {
		double runTimeScale = (double)worstRunTime/thread.getTime();
		System.out.println("Thread num: "+ tarray.indexOf(thread)+" runtime: "+thread.getTime());
		System.out.println("Thread num: "+tarray.indexOf(thread)+" effeciency factor: "+runTimeScale);
	}
	long totalTime =0;
	for(MyThread thread : tarray) {
		totalTime += thread.getTime();
	}
	System.out.print("SUM "+sum+" Total run time in nanoseconds: "+totalTime);
	}
	
}

