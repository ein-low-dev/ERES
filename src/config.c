/*

   List of color for foreground and background.

# Foreground
FG_DEFAULT	
FG_BLACK	
FG_DARK_RED	
FG_DARK_GREEN	
FG_DARK_YELLOW	
FG_DARK_BLUE	
FG_DARK_MAGENTA	
FG_DARK_CYAN	
FG_DARK_GRAY	
FG_LIGHT_GRAY	
FG_RED		
FG_GREEN	
FG_YELLOW	
FG_BLUE		
FG_MAGENTA	
FG_CYAN		
FG_WHITE	
                
# Background
BG_DEFAULT	
BG_BLACK	
BG_DARK_RED	
BG_DARK_GREEN	
BG_DARK_YELLOW	
BG_DARK_BLUE	
BG_DARK_MAGENTA	
BG_DARK_CYAN	
BG_DARK_GRAY	
BG_LIGHT_GRAY	
BG_RED		
BG_GREEN	
BG_YELLOW	
BG_BLUE		
BG_MAGENTA	
BG_CYAN		
BG_WHITE

After you finish with the color, you can use CLR_RESET

*/


// Prompt config
char *prompt_config[] = {
	"\n",
	FG_BLUE, "]==", FG_WHITE, " ERES ", FG_BLUE, "==", "\n",
	"]== ", FG_DARK_GRAY, "eres", FG_DEFAULT, ":", FG_DARK_GRAY, "?dir", FG_DEFAULT,"> ", CLR_RESET
};


