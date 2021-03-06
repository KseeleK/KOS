#ifndef _EXC_H
#define _EXC_H

#include <zjunix/pc/sched.h>
#include <page.h>

typedef void ( *exc_fn )( unsigned int, unsigned int, context * );

extern exc_fn exceptions[ 32 ];

void do_page_fault(PageTableEntry *pte, unsigned int vpn );
void do_exceptions( unsigned int status, unsigned int cause, context *pt_context, unsigned int bad_addr );
void register_exception_handler( int index, exc_fn fn );
void init_exception();
void tlb_refill(unsigned int status, unsigned int cause, context* pt_context, unsigned int bad_addr);
void tlb_load(unsigned int status, unsigned int cause, context* pt_context, unsigned int bad_addr);

#endif