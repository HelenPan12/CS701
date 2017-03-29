// asp.h

#include "systemc.h"
#ifndef ASP_H
#define ASP_H

template<int T>
SC_MODULE(asp)
{
    //sc_in<bool> reset;
    sc_in<bool> valid;
    sc_out<bool> Res_ready;
    sc_out<bool> busy;
    sc_in<sc_int<32>> Data_in;
    sc_out<sc_int<32>> Data_out;


    sc_int<bool> memsel;
    sc_int<4> opcode;
    sc_int<T> A;
    sc_int<T> B;
    int i;

    void my_asp();
    void store0();
    void store1();
    void InvokeASPXOR_A();
    void InvokeASPXOR_B();
    void InvokeASPMAC();
    void InvokeASPAVE_A();
    void InvokeASPAVE_B();
                             
    SC_CTOR(asp)
    {
		SC_METHOD(my_asp);
			sensitive << valid.pos( );
    }
};

