public class UsingValuePair{
    
    public static void main(final String[] args) throws InterruptedException{
        
        final ValuePair obj1 = new ValuePair();
        obj1.setValue(1);

        final ValuePair obj2 = new ValuePair();
        obj2.setValue(5);

        final Thread thread1 = new Thread("Thread 1"){
            @Override
            public void run(){
                obj1.copy(obj2);
            }
        };

        final Thread thread2 = new Thread("Thread 2"){
            @Override
            public void run(){
                obj1.setValue(12);
            }
        };

        thread1.start();
        thread2.start();

        thread1.join();
        thread2.join();

        System.out.println(obj1);
    }
}