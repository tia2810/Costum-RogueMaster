#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <m-string.h>

/* Cli type
 * Anonymous structure. Use cli_i.h if you need to go deeper.
 */
typedef struct Cli Cli;

/* Cli callback function pointer.
 * Implement this interface and use add_cli_command
 * @param args - string with what was passed after command
 * @param context - pointer to whatever you gave us on cli_add_command
 */
typedef void (*CliCallback)(Cli* cli, string_t args, void* context);

/* Add cli command
 * Registers you command callback
 * @param cli - pointer to cli instance
 * @param name - command name
 * @param callback - callback function
 * @param context - pointer to whatever we need to pass to callback
 */
void cli_add_command(Cli* cli, const char* name, CliCallback callback, void* context);

/* Delete cli command
 * @param cli - pointer to cli instance
 * @param name - command name
 */
void cli_delete_command(Cli* cli, const char* name);

/* Read from terminal
 * Do it only from inside of cli call.
 * @param cli - Cli instance
 * @param buffer - pointer to buffer
 * @param size - size of buffer in bytes
 * @return bytes written
 */
size_t cli_read(Cli* cli, uint8_t* buffer, size_t size);

/* Not blocking check for interrupt command received
 * @param cli - Cli instance
 */
bool cli_cmd_interrupt_received(Cli* cli);

/* Write to terminal
 * Do it only from inside of cli call.
 * @param cli - Cli instance
 * @param buffer - pointer to buffer
 * @param size - size of buffer in bytes
 * @return bytes written
 */
void cli_write(Cli* cli, uint8_t* buffer, size_t size);

/* Read character
 * @param cli - Cli instance
 * @return char
 */
char cli_getc(Cli* cli);

/* New line 
 * Send new ine sequence
 */
void cli_nl();

#ifdef __cplusplus
}
#endif
