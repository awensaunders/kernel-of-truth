#ifndef _PCI_H
#define _PCI_H

#include <stdint.h>

#define PCI_VENDOR_ID            0x00
#define PCI_DEVICE_ID            0x02
#define PCI_COMMAND              0x04
#define PCI_STATUS               0x06
#define PCI_REVISION_ID          0x08

#define PCI_PROG_IF              0x09
#define PCI_SUBCLASS             0x0a
#define PCI_CLASS                0x0b
#define PCI_CACHE_LINE_SIZE      0x0c
#define PCI_LATENCY_TIMER        0x0d
#define PCI_HEADER_TYPE          0x0e
#define PCI_BIST                 0x0f
#define PCI_BAR0                 0x10
#define PCI_BAR1                 0x14
#define PCI_BAR2                 0x18
#define PCI_BAR3                 0x1C
#define PCI_BAR4                 0x20
#define PCI_BAR5                 0x24

#define PCI_INTERRUPT_LINE       0x3C

#define PCI_SECONDARY_BUS        0x09

#define PCI_HEADER_TYPE_DEVICE  0
#define PCI_HEADER_TYPE_BRIDGE  1
#define PCI_HEADER_TYPE_CARDBUS 2

#define PCI_TYPE_BRIDGE 0x0604
#define PCI_TYPE_SATA   0x0106

#define PCI_ADDRESS_PORT 0xCF8
#define PCI_VALUE_PORT   0xCFC

#define PCI_NONE 0xFFFF

typedef void (*pci_func_t)(uint32_t device, uint16_t vendor_id,
        uint16_t device_it, void *extra);

static inline uint8_t pci_get_bus(uint32_t dev) {
    return (dev >> 16) & 0xff;
}

static inline uint8_t pci_get_slot(uint32_t dev) {
    return (dev >> 8) & 0xff;
}

static inline uint8_t pci_get_func(uint32_t dev) {
    return dev;
}

static inline uint32_t pci_get_addr(uint32_t device, int field) {
    return 0x80000000 | (pci_get_bus(device) << 16) |
           (pci_get_slot(device) << 11) | (pci_get_func(device) << 8) |
           (field & 0xfc);
}

static inline uint32_t pci_box_device(int bus, int slot, int func) {
    return (bus << 16) | (slot << 8) | func;
}

uint32_t pci_read_field(uint32_t dev, int field, int size);
void pci_write_field(uint32_t dev, int field, int size, uint32_t value);
void pci_scan(pci_func_t f, int type, void *extra);

#endif
