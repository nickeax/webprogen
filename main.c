#include<stdio.h>
#include<windows.h> // change this to suit your OS!

#define PATHLENGTH 512

int main(int argc, char const *argv[])
{  
  FILE *fp;
  int check = 0;
  int i = 0;
  int flags[4]; 
  char projectName[PATHLENGTH];
  char pathIndexFile[PATHLENGTH];
  char pathJavaScriptFile[PATHLENGTH];
  char pathCSSFile[PATHLENGTH];
  char headTitle[PATHLENGTH];

  // if no project name, quit with usage:
  if(argc < 2) {
    printf("usage: directory>webprogen <PROJECT-NAME>");    
    return 0;
  };  
  
  sprintf(projectName, "%s", argv[1]);
  sprintf(headTitle, "  <title>%s</title>\n", projectName);

  check = CreateDirectory(projectName, NULL);  
  if (check) {
    printf("Project '%s' created.\n", projectName);
  } else {
    printf("Unable to create project.\n");
    return -1;
  }
  const char *indexData[50];
  indexData[0] = "<!DOCTYPE html>\n";
  indexData[1] = "<html lang='en'>\n";
  indexData[2] = "  <head>\n";
  indexData[3] = "    <meta charset='UTF-8'>\n";
  indexData[4] = "    <meta name='viewport' content='width=device-width, initial-scale=1.0'>\n";
  indexData[5] = "    <meta http-equiv='X-UA-Compatible' content='ie=edge'>\n";
  indexData[6] = "    <link rel='stylesheet' href='css/style.css'>\n"; 
  indexData[7] = headTitle;
  indexData[8] = "  </head>\n";
  indexData[9] = "  <body>\n";
  indexData[10] = "";
  indexData[11] = "\n";
  indexData[12] = "    <script src='scripts/index.js'></script>\n";
  indexData[13] = "  </body>\n"; 
  indexData[14] = "</html>\n";
  indexData[15] = "ZZZ";

  sprintf(pathCSSFile, "%s\\%s",projectName, "css");
  sprintf(pathJavaScriptFile, "%s\\%s",projectName, "scripts");
  check = CreateDirectory(pathCSSFile, NULL); 
  check = CreateDirectory(pathJavaScriptFile, NULL);

  sprintf(pathCSSFile, "%s\\%s", pathCSSFile, "main.css"); 
  sprintf(pathJavaScriptFile, "%s\\%s", pathJavaScriptFile, "index.js"); 
  sprintf(pathIndexFile, "%s\\%s", projectName, "index.html"); 

  fp = fopen(pathCSSFile, "w");
  fclose(fp);
  fp = fopen(pathJavaScriptFile, "w");
  fclose(fp);
  fp = fopen(pathIndexFile, "w");
  for(i = 0; i < sizeof(indexData); i++) {
    if(indexData[i] == "ZZZ") break;
    fputs(indexData[i], fp);
  };
  fclose(fp);
  
  return 0;
}
