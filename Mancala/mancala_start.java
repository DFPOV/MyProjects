public class mancala_start {
	//
	static mancala_gui humangui = new mancala_gui();
	static mancala_gui_AI AIgui = new mancala_gui_AI();
	
	public mancala_start(int choice, int mode) {		
		
		if (mode == 1) {
			//
			humangui.fillbuttons(choice);
			humangui.setgui();
		}
		
		if (mode == 2) {
			//
			AIgui.fillbuttons(choice);
			AIgui.setgui();
		}		
	}
}
