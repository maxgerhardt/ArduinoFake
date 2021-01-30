/*
  TwoWire.h - TWI/I2C library for Arduino & Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  Modified 2012 by Todd Krein (todd@krein.org) to implement repeated starts
  Modified 2020 by Greyson Christoforo (grey@christoforo.net) to implement timeouts
*/

#ifndef TwoWire_h
#define TwoWire_h

#include <inttypes.h>
#include "ArduinoFake.h"
#include "StreamFake.h"
#include "PrintFake.h"
#include "Wire.h"

#define BUFFER_LENGTH 32

// WIRE_HAS_END means Wire has end()
#define WIRE_HAS_END 1

class TwoWire : public Stream
{
  private:
    static uint8_t rxBuffer[];
    static uint8_t rxBufferIndex;
    static uint8_t rxBufferLength;

    static uint8_t txAddress;
    static uint8_t txBuffer[];
    static uint8_t txBufferIndex;
    static uint8_t txBufferLength;

    static uint8_t transmitting;
    static void (*user_onRequest)(void);
    static void (*user_onReceive)(int);
    static void onRequestService(void);
    static void onReceiveService(uint8_t*, int);
  public:
    TwoWire() {}
    void begin();
    void begin(uint8_t);
    void begin(int);
    void end();
    void setClock(uint32_t);
    void setWireTimeout(uint32_t timeout = 25000, bool reset_with_timeout = false);
    bool getWireTimeoutFlag(void);
    void clearWireTimeoutFlag(void);
    void beginTransmission(uint8_t);
    void beginTransmission(int);
    uint8_t endTransmission(void);
    uint8_t endTransmission(uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint32_t, uint8_t, uint8_t);
    uint8_t requestFrom(int, int);
    uint8_t requestFrom(int, int, int);
    virtual size_t write(uint8_t);
    virtual size_t write(const uint8_t *, size_t);
    virtual int available(void);
    virtual int read(void);
    virtual int peek(void);
    virtual void flush(void);
    void onReceive( void (*)(int) );
    void onRequest( void (*)(void) );

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write;
};


struct TwoWireFake : public StreamFake
{
    virtual void begin() = 0;
    virtual void begin(uint8_t) = 0;
    virtual void begin(int) = 0;
    virtual void end() = 0;
    virtual void setClock(uint32_t) = 0;
    virtual void setWireTimeout(uint32_t timeout = 25000, bool reset_with_timeout = false) = 0;
    virtual bool getWireTimeoutFlag(void) = 0;
    virtual void clearWireTimeoutFlag(void) = 0;
    virtual void beginTransmission(uint8_t) = 0;
    virtual void beginTransmission(int) = 0;
    virtual uint8_t endTransmission(void) = 0;
    virtual uint8_t endTransmission(uint8_t) = 0;
    virtual uint8_t requestFrom(uint8_t, uint8_t) = 0;
    virtual uint8_t requestFrom(uint8_t, uint8_t, uint8_t) = 0;
    virtual uint8_t requestFrom(uint8_t, uint8_t, uint32_t, uint8_t, uint8_t) = 0;
    virtual uint8_t requestFrom(int, int) = 0;
    virtual uint8_t requestFrom(int, int, int) = 0;
    virtual size_t write(uint8_t) = 0;
    virtual size_t write(const uint8_t *, size_t) = 0;
    virtual int available(void) = 0;
    virtual int read(void) = 0;
    virtual int peek(void) = 0;
    virtual void flush(void) = 0;
    virtual void onReceive( void (*)(int) ) = 0;
    virtual void onRequest( void (*)(void) ) = 0;

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using PrintFake::write;
};

//extern TwoWire Wire;


class TwoWireFakeProxy : public StreamFakeProxy, public TwoWire
{
    private:
        TwoWireFake* twoWireFake;

    public:
        TwoWireFakeProxy(TwoWireFake* fake) : StreamFakeProxy(fake)
        {
            twoWireFake = fake;
        }

        TwoWireFake* getTwoWireFake()
        {
            return twoWireFake;
        }
};

extern TwoWire Wire;

#endif
