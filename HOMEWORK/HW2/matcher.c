#include "matcher.h"
static int inputcounter = 0;
static int braket_counter = 0;
/**
 * Implementation of your matcher function, which
 * will be called by the main program.
 *
 * You may assume that both line and pattern point
 * to reasonably short, null-terminated strings.
 */
int rgrep_matches(char *line, char *pattern) {

	//
	// TODO put your code here.
	//

	/////////////////////////////////////////////////////
	if (*pattern != '\0'&&*line != '\0'){
		if (*pattern != *line && *pattern != '.' && *pattern != '{' && *pattern!='\ '){
			if (inputcounter == 0){
				line += 1;
				rgrep_matches(line, pattern);
			}
			else
				return -1;
		}
		else if (*pattern  == '{') {
			//if encounter the bracket,and the 
			int begin = *(pattern + 1);
			int end;
			if (*(pattern + 3) != '}'){
				end = *(pattern + 2);
			}
			else{
			//if it is the {m,} pattern
				int result = 0;
				braket_counter = 0;
				char *line_iterator = line;
				while (*line_iterator != '\0'){
					//loop through all  the possible match of the following word of pattern
					if (*(pattern + 4) == *line_iterator){
						int a=rgrep_matches(line_iterator, pattern+4);
						//if the following pattern matches the rest:
						if (a == 1){
							if (braket_counter >= begin){
								return 1;
							}
							//the pattern in between is less than the {m,}
							else
								return -1;
						}
						//else the  }XXX not in the line pattern, continue the while loop
						else
							line_iterator += 1;
					}
					else{
						if (*(pattern - 1) != '.'){
							if (*(line_iterator) == *(pattern - 1)){
								braket_counter += 1;
							}
						}
						else{
							braket_counter += 1;
						}
						//add the line_iterator
						line_iterator += 1;
					}
				}
			//end of the line_iterator;
			}

			int continue_position = -1;
			for (int i = begin; i < end; i++){
				int result = (*(line + i) == *(pattern + 1));
				if (result == 1){
					continue_position = i;
					break;
				}
			}
			//if did not find the proper one
			if (continue_position == -1){
				return 0;
			}
			//found the proper position,recursively apply the method
			else{
				inputcounter += 1;
				rgrep_matches(line, pattern);
			}
		}
		//when the char is '.', get the next char to compare
		else if (*pattern == '.'){
			inputcounter += 1;
			rgrep_matches(line+1, pattern + 1);
		}
		//if the slash
		else if (*pattern == '\ '){
			if (*(line + 1) == *(pattern + 1)){
				inputcounter += 1;
				rgrep_matches(line, pattern);
			}
			else
				return -1;
		}
		//they are equal,both forward to the next char
		else{
			inputcounter += 1;
			rgrep_matches(line + 1, pattern + 1);
		}
		
	}
	if (*(pattern) == '\0'){
		return 1;
	}
	else
		return -1;
}