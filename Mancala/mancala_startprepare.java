public class mancala_startprepare {
	
	public static int choice1;
	
	public mancala_startprepare(int mode) {
		mancala_start start = new mancala_start(choice1,mode);
	}
	
	public static void Pass(int choice) {
		choice1 = choice;
	}
}