/**
 * HOST PC tool to generate bin to hex header file "mpfs_dtb.h"
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	FILE *fp1 = NULL;
	unsigned char data;
	unsigned int i = 0;
		
	if (argv[1] == NULL)
	{
		printf("Error input file <bin> not specified\n");
		printf("Usage: ./bin2hex <app.bin/dtb>\n");
		return -1;
	}
	fp = fopen(argv[1], "rb+");
	if (!fp)
	{
		printf("Error opening file %s\n", argv[1]);
		return -1;
	}
	fp1 = fopen("./mpfs-dtb.h", "w+");
	if (!fp1)
	{
		printf("Error opening file mpfs-dtb.h");
		return -1;
	}

	fprintf(fp1, "/*\n");
	fprintf(fp1, " *  Declarations for C structure representing binary file mpfs.dtb\n");
	fprintf(fp1, " *\n");
	fprintf(fp1, " *  WARNING: Automatically generated -- do not edit!\n");
	fprintf(fp1, " */\n");
	fprintf(fp1, "\n");
	fprintf(fp1, "#ifndef __system_dtb_h\n");
	fprintf(fp1, "#define __system_dtb_h\n");
	fprintf(fp1, "\n");
	fprintf(fp1, "#include <rtems/score/basedefs.h>\n");
	fprintf(fp1, "#include <sys/types.h>\n");
	fprintf(fp1, "\n");
	fprintf(fp1, "const unsigned char system_dtb[] RTEMS_ALIGNED(8) = {\n");
	fprintf(fp1, " ");	
	while (fread(&data, 1, 1, fp) != 0) {
		if (data < 16)
			fprintf(fp1, " 0x0%x,", data);
		else			
			fprintf(fp1, " 0x%x,", data);
		if (++i == 12)
		{
			i = 0;
			fprintf(fp1, "\n");	
			fprintf(fp1, " ");	
		}
		
	}
	fprintf(fp1, "\n");	
	fprintf(fp1, "};");	
	fprintf(fp1, "\n");
	fprintf(fp1, "\n");
	fprintf(fp1, "#endif /* __system_dtb_h */\n");
	fclose(fp);
	fclose(fp1);
}
