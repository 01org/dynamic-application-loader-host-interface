/*
   Copyright 2010-2016 Intel Corporation

   This software is licensed to you in accordance
   with the agreement between you and Intel Corporation.

   Alternatively, you can use this file in compliance
   with the Apache license, Version 2.


   Apache License, Version 2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef __SMOKETEST_H__
#define __SMOKETEST_H__

#include "jhi_version.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

#ifdef _WIN32
#define FILECHARLEN wcslen
#else
#define FILECHARLEN strlen
#endif // _WIN32

	// globals and macros


#define MAX_APPLETS_BH1 5
#define MAX_APPLETS_BH2 31

#define MAX_SESSIONS_BH1 5       // ME7-ME10, BYT, CHT
#define MAX_SESSIONS_BH2_GEN1 10 // ME11.0-ME12.0
#define MAX_SESSIONS_BH2_GEN2 16 // TXE3.0 and up, ME13.0 and up

#define SAR_MAX_BUFFER_SIZE 40
#define BUFFER_SIZE 10000
#define EVENTS_BUFFER_SIZE 2048
#define APP_PROPERTY_BUFFER_SIZE 2048
#define LEN_DIR 1024
#define INTEL_SD_UUID "BD2FBA36A2D64DAB9390FF6DA2FEF31C"
#define OEM_SD_UUID "FAA5DB69EB0545F0AD48079B456986EA"
#define OEM_SD_UUID_BIN {0xFA,0xA5,0xDB,0x69,0xEB,0x05,0x45,0xF0,0xAD,0x48,0x07,0x9B,0x45,0x69,0x86,0xEA}


	// test functions
	void test_01_send_and_recieve(JHI_HANDLE hJOM);						// test # 1
	void test_02_sessions_api(JHI_HANDLE hJOM);							// test # 2
	void test_03_events(JHI_HANDLE hJOM);								// test # 3
	void test_04_max_sessions(JHI_HANDLE hJOM);							// test # 4
	void test_05_get_applet_property(JHI_HANDLE hJOM);					// test # 5
	void test_06_max_installed_applets(JHI_HANDLE hJOM);				// test # 6
	void test_07_install_dalp(JHI_HANDLE hJOM);							// test # 7
	void test_08_get_version_info(JHI_HANDLE hJOM);						// test # 8
	void test_09_shared_session(JHI_HANDLE hJOM);						// test # 9
	void test_10_sar_timeout(JHI_HANDLE hJOM);							// test # 10
	void test_11_init_deinit(JHI_HANDLE *hJOM);							// test # 11
	void test_12_negative_test_events(JHI_HANDLE hJOM);					// test # 12
	void test_13_negative_test_send_and_recieve(JHI_HANDLE hJOM);		// test # 13
	void test_14_negative_test_get_applet_property(JHI_HANDLE hJOM);	// test # 14
	void test_15_negative_test_get_version_info(JHI_HANDLE hJOM);		// test # 15
	void test_16_negative_test_install_applet(JHI_HANDLE hJOM);			// test # 16
	void test_17_list_installed_applets();								// test # 17
	void test_18_admin_install_uninstall();								// test # 18
	void test_19_admin_install_with_session(JHI_HANDLE hJOM);			// test # 19
	void test_20_admin_updatesvl();										// test # 20
	void test_21_admin_query_tee_metadata();							// test # 21
	void test_22_oem_signing();											// test # 22
	void test_23_applet_encryption(JHI_HANDLE hJOM);					// test # 23

#define TESTS_NUM 23

	// helper functions
	TEE_STATUS readFileAsBlob(const FILECHAR* filepath, vector<uint8_t>& blob);
	void onEvent(JHI_SESSION_HANDLE SessionHandle,JHI_EVENT_DATA eventData);
	int AppPropertyCall(JHI_HANDLE hJOM, const FILECHAR *AppProperty, FILECHAR rxBuffer[APP_PROPERTY_BUFFER_SIZE], JVM_COMM_BUFFER* txrx);
	void GetFullFilename(wchar_t* szCurDir, wchar_t* fileName);
	void exit_test(int result);
	void print_menu();
	void run_cmd(int cmd, JHI_HANDLE *phJOM);
	void print_buffer(unsigned char* buffer, int len);
	void fill_buffer(unsigned char* buffer, int len);
	int check_buffer(unsigned char* rxBuffer, int len);
	bool getFWVersion(VERSION* fw_version);
	FILESTRING getEchoFileName(int num);
	string getEchoUuid(int num);
	JHI_VM_TYPE get_vm_type();

	// applet properties
#define SPOOLER_APP_ID "BA8D164350B649CC861D2C01BED14BE8"

#define ECHO_APP_ID "d1de41d82b844feaa7fa1e4322f15dee"
#define ECHO_FILENAME FILEPREFIX("/echo.dalp")
#define ECHO_ACP_INSTALL_SIG_VER_1_FILENAME FILEPREFIX("/EchoInstallSigVer1.acp")
#define ECHO_ACP_UNINSTALL_SIG_VER_1_FILENAME FILEPREFIX("/EchoUninstallSigVer1.acp")
#define ECHO_ACP_UPDATESVL_SIG_VER_1_FILENAME FILEPREFIX("/UpdateSVLSigVer1.acp")

#define ECHO_ACP_INSTALL_SIG_VER_2_FILENAME FILEPREFIX("/EchoInstallSigVer2.acp")
#define ECHO_ACP_UNINSTALL_SIG_VER_2_FILENAME FILEPREFIX("/EchoUninstallSigVer2.acp")
#define ECHO_ACP_UPDATESVL_SIG_VER_2_FILENAME FILEPREFIX("/UpdateSVLSigVer2.acp")

#define ACP_INSTALL_SD_FILENAME FILEPREFIX("/InstallSD.acp")
#define ACP_UNINSTALL_SD_FILENAME FILEPREFIX("/UninstallSD.acp")
#define ACP_INSTALL_SD_APPLET_FILENAME FILEPREFIX("/OemEchoInstalll.acp")
#define ACP_UNINSTALL_SD_APPLET_FILENAME FILEPREFIX("/EchoUninstall.acp")

#define ECHO_ENCRYPTED_FILENAME FILEPREFIX("/OemEncryptedEchoInstall.acp")

	//SGX applet
	//#define ECHO_APP_ID "afc6721e506e45a99368663027934feb"
	//#define ECHO_FILENAME FILEPREFIX("/sgx.dalp")
	//#define ECHO_FILENAME_TO_PRINT "sgx applet"

#define ECHO_1_APP_ID "d1de41d82b844feaa7fa1e4322f15de1"
#define SIG_VERSION_2K_APPLET_SIGNING 1
#define SIG_VERSION_3K_APPLET_SIGNING 2

#define EVENT_SERVICE_APP_ID "a525599fc5214aae9f952f268fa54416"
#define EVENT_SERVICE_FILENAME FILEPREFIX("/EventService.dalp")

#define Isspace(c) ( ((c) == ' ') || ((c) == '\r') || ((c) == '\n') )

#endif //__SMOKETEST_H__