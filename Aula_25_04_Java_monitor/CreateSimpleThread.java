public class CreateSimpleThread{
	private static void log(final String msg){
		System.out.printf("%tT[%s] %s%n", 
						System.currentTimeMillis(), 
						Thread.currentThread().getName(), 
						msg);
	}
	public static void main(final String[] args) throws InterruptedException{

		CreateSimpleThread.log("Start");

		final Thread t = new Thread("My Thread"){
			@Override
			public void run(){
				CreateSimpleThread.log("Hello Thread");
			}
		};
		t.start();

		CreateSimpleThread.log("Waiting thread");
		t.join();

		CreateSimpleThread.log("Done");
	}
}