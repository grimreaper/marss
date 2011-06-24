
#ifndef BASE_CORE_H
#define BASE_CORE_H

#include <ptlsim.h>
#include <machine.h>
#include <statsBuilder.h>
#include <memoryHierarchy.h>

namespace Core {

    struct BaseCore {
        BaseCore(BaseMachine& machine);

        virtual void reset() = 0;
        virtual bool runcycle() = 0;
        virtual void check_ctx_changes() = 0;
        virtual void flush_tlb(Context& ctx) = 0;
        virtual void flush_tlb_virt(Context& ctx, Waddr virtaddr) = 0;
        virtual void dump_state(ostream& os) = 0;
        virtual void update_stats(PTLsimStats* stats) = 0;
        virtual void flush_pipeline() = 0;
        virtual W64  get_insns_committed() = 0;
        virtual W8 get_coreid() = 0;

        void update_memory_hierarchy_ptr();

        BaseMachine& machine;
        Memory::MemoryHierarchy* memoryHierarchy;
    };

};

#endif // BASE_CORE_H
