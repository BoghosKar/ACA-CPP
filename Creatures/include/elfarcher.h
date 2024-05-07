#ifndef ELFARCHER_H
#define ELFARCHER_H

#include "elf.h"
#include "archer.h"

class ElfArcher : public Elf, public Archer
{
public:
    ElfArcher();

    ~ElfArcher();
};

#endif // ELFARCHER_H
