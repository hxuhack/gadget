#include "sec.h"
#include "libdeclare.h"
//#include<android/log.h>
#include<pthread.h>


int LXFCKZZKMUNQUAEAJPQUTSLCOKSJHZT(char* line, char* libname)
{
	
	 //__android_log_print(ANDROID_LOG_INFO, "NVO", "get_libinfo: line: %s", line);
	char* save_ptr;
    char* item;
    //pthread_mutex_t counter_lock = PTHREAD_MUTEX_INITIALIZER;  
        int counter = 0;

    while (item = strtok_r(line, " ", &save_ptr)){
        //__android_log_print(ANDROID_LOG_INFO, "NVO", "item: %s", item);
        //__android_log_print(ANDROID_LOG_INFO, "NVO", "save_ptr: %s", save_ptr);
        if((int) item[0] == 10)
               break;
	snprintf(libname, strlen(item)+1, "%s", item);
	line = save_ptr;
	//__syn_fetch_and_add(&counter, 1);
        counter++;
    } 
	if (libname[strlen(libname)-1] == '\n')
		libname[strlen(libname)-1] = '\0';
	if(counter < 6){	
		//__android_log_print(ANDROID_LOG_INFO, "NVO", "get_libinfo: return -1");
    		return -1;
	} 
	else {
		//__android_log_print(ANDROID_LOG_INFO, "NVO", "get_libinfo: return 0");
		return 0;
	}
    
}

bool SYZWIYVUKSJDOKJOVYFRTZEWPOQYVPS(char* libname){
    int i;
    for(i = 0; i < dictlength; i++){

	if(strcmp(libdict[i].libname,libname) == 0) {
	    return true;
        }
    }
    return false;
}

bool POTOYTLVFDEITQSINSNEMOIKEYACVSW(char* libname){
	//should be (deleted), the word maybe breaked into two lines;
    if(strstr(libname, "(d"))
    	return true;
    return false;
}

bool LIRZIKMDQQIAJAUTONIUBXDNBBNFXHE(char* libname){
    if(strstr(libname, "[stack:"))
    	return true;
    return false;
}

bool KPXLYKXDAPLCBOXUCKDWNABADFPKCXQ(char* libname){
    if(strstr(libname, "/dev/"))
    	return true;
    return false;
}
bool OMOZMYYQAODCPRBLVNOUAQXAVCSGGPY(char* libname){
    if(strstr(libname, "/system/"))
    	return true;
    return false;
}

bool UDMVQMUIOKLTBFUMCIBWKTUNPYFXFUV(char* libname){
    if(strstr(libname, "/data/dalvik-cache/"))
    	return true;
    return false;
}
bool ZXKXPYRXNDLGEQAQSKTRXPNKGLPDQLA(char* libname){
    if(strstr(libname, "libnvo.so"))
    	return true;
    return false;
}

int SKMPALIZALKGPCIHXVDOSSBEYOVDFGF(pid_t pid, char message[MSG_SIZE][128])
{
    FILE *fp;
    char filename[32];
    char line[128];
    char libname[64];
    int counter=0;

    if (pid > 0) {
	sprintf(filename, "/proc/%d/maps", pid);
	fp = fopen(filename, "r");
	if (!fp) 
            return -1;

        while(fgets(line, 127, fp) != NULL){
   	    //__android_log_print(ANDROID_LOG_INFO, "NVO", "line: %s", line);
            if(LXFCKZZKMUNQUAEAJPQUTSLCOKSJHZT(line, libname) == -1)
		continue;
            if(POTOYTLVFDEITQSINSNEMOIKEYACVSW(libname) 
		|| ZXKXPYRXNDLGEQAQSKTRXPNKGLPDQLA(libname)
		|| LIRZIKMDQQIAJAUTONIUBXDNBBNFXHE(libname) 
		|| KPXLYKXDAPLCBOXUCKDWNABADFPKCXQ(libname) 
		|| OMOZMYYQAODCPRBLVNOUAQXAVCSGGPY(libname) 
		|| UDMVQMUIOKLTBFUMCIBWKTUNPYFXFUV(libname) == true)
		continue;

	    if(SYZWIYVUKSJDOKJOVYFRTZEWPOQYVPS(libname) == false){
		 //snprintf packs the string with '\0', hence the size should be strlen + 1
		//__android_log_print(ANDROID_LOG_INFO, "NVO", "libname: %s", libname);
           	 if(counter > MSG_SIZE - 1)
	         	break;
            	snprintf(message[counter], strlen(libname)+1, "%s", libname);
		//__android_log_print(ANDROID_LOG_INFO, "NVO", "message[%d]: %s", counter,message[counter]);
		counter++;
	    }
        }

	fclose(fp);
    }
	//__android_log_print(ANDROID_LOG_INFO, "NVO", "EXIT read_map");
    return counter;
}


int ORVQKRVANVDEZNMEGKOJCCRHVXOTVGI(char** out)
{
    pid_t pid = getpid();
    int size = SKMPALIZALKGPCIHXVDOSSBEYOVDFGF(pid, out);
    return size;
}
