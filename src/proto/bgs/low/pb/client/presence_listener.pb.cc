// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bgs/low/pb/client/presence_listener.proto

#include "bgs/low/pb/client/presence_listener.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_bgs_2flow_2fpb_2fclient_2faccount_5ftypes_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_AccountId_bgs_2flow_2fpb_2fclient_2faccount_5ftypes_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_bgs_2flow_2fpb_2fclient_2fpresence_5ftypes_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_PresenceState_bgs_2flow_2fpb_2fclient_2fpresence_5ftypes_2eproto;
namespace bgs {
namespace protocol {
namespace presence {
namespace v1 {
class SubscribeNotificationDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<SubscribeNotification> _instance;
} _SubscribeNotification_default_instance_;
class StateChangedNotificationDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<StateChangedNotification> _instance;
} _StateChangedNotification_default_instance_;
}  // namespace v1
}  // namespace presence
}  // namespace protocol
}  // namespace bgs
static void InitDefaultsscc_info_StateChangedNotification_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::bgs::protocol::presence::v1::_StateChangedNotification_default_instance_;
    new (ptr) ::bgs::protocol::presence::v1::StateChangedNotification();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::bgs::protocol::presence::v1::StateChangedNotification::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_StateChangedNotification_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_StateChangedNotification_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto}, {
      &scc_info_AccountId_bgs_2flow_2fpb_2fclient_2faccount_5ftypes_2eproto.base,
      &scc_info_PresenceState_bgs_2flow_2fpb_2fclient_2fpresence_5ftypes_2eproto.base,}};

static void InitDefaultsscc_info_SubscribeNotification_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::bgs::protocol::presence::v1::_SubscribeNotification_default_instance_;
    new (ptr) ::bgs::protocol::presence::v1::SubscribeNotification();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::bgs::protocol::presence::v1::SubscribeNotification::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_SubscribeNotification_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_SubscribeNotification_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto}, {
      &scc_info_AccountId_bgs_2flow_2fpb_2fclient_2faccount_5ftypes_2eproto.base,
      &scc_info_PresenceState_bgs_2flow_2fpb_2fclient_2fpresence_5ftypes_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::presence::v1::SubscribeNotification, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::presence::v1::SubscribeNotification, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::presence::v1::SubscribeNotification, subscriber_id_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::presence::v1::SubscribeNotification, state_),
  0,
  ~0u,
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::presence::v1::StateChangedNotification, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::presence::v1::StateChangedNotification, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::presence::v1::StateChangedNotification, subscriber_id_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::presence::v1::StateChangedNotification, state_),
  0,
  ~0u,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 7, sizeof(::bgs::protocol::presence::v1::SubscribeNotification)},
  { 9, 16, sizeof(::bgs::protocol::presence::v1::StateChangedNotification)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::bgs::protocol::presence::v1::_SubscribeNotification_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::bgs::protocol::presence::v1::_StateChangedNotification_default_instance_),
};

const char descriptor_table_protodef_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n)bgs/low/pb/client/presence_listener.pr"
  "oto\022\030bgs.protocol.presence.v1\032&bgs/low/p"
  "b/client/presence_types.proto\032%bgs/low/p"
  "b/client/account_types.proto\032!bgs/low/pb"
  "/client/rpc_types.proto\"\212\001\n\025SubscribeNot"
  "ification\0229\n\rsubscriber_id\030\001 \001(\0132\".bgs.p"
  "rotocol.account.v1.AccountId\0226\n\005state\030\002 "
  "\003(\0132\'.bgs.protocol.presence.v1.PresenceS"
  "tate\"\215\001\n\030StateChangedNotification\0229\n\rsub"
  "scriber_id\030\001 \001(\0132\".bgs.protocol.account."
  "v1.AccountId\0226\n\005state\030\002 \003(\0132\'.bgs.protoc"
  "ol.presence.v1.PresenceState2\226\002\n\020Presenc"
  "eListener\022a\n\013OnSubscribe\022/.bgs.protocol."
  "presence.v1.SubscribeNotification\032\031.bgs."
  "protocol.NO_RESPONSE\"\006\202\371+\002\010\001\022g\n\016OnStateC"
  "hanged\0222.bgs.protocol.presence.v1.StateC"
  "hangedNotification\032\031.bgs.protocol.NO_RES"
  "PONSE\"\006\202\371+\002\010\002\0326\202\371+,\n*bnet.protocol.prese"
  "nce.v1.PresenceListener\212\371+\002\010\001"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto_deps[3] = {
  &::descriptor_table_bgs_2flow_2fpb_2fclient_2faccount_5ftypes_2eproto,
  &::descriptor_table_bgs_2flow_2fpb_2fclient_2fpresence_5ftypes_2eproto,
  &::descriptor_table_bgs_2flow_2fpb_2fclient_2frpc_5ftypes_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto_sccs[2] = {
  &scc_info_StateChangedNotification_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto.base,
  &scc_info_SubscribeNotification_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto_once;
static bool descriptor_table_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto = {
  &descriptor_table_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto_initialized, descriptor_table_protodef_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto, "bgs/low/pb/client/presence_listener.proto", 749,
  &descriptor_table_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto_once, descriptor_table_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto_sccs, descriptor_table_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto_deps, 2, 3,
  schemas, file_default_instances, TableStruct_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto::offsets,
  file_level_metadata_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto, 2, file_level_enum_descriptors_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto, file_level_service_descriptors_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto)), true);
namespace bgs {
namespace protocol {
namespace presence {
namespace v1 {

// ===================================================================

void SubscribeNotification::InitAsDefaultInstance() {
  ::bgs::protocol::presence::v1::_SubscribeNotification_default_instance_._instance.get_mutable()->subscriber_id_ = const_cast< ::bgs::protocol::account::v1::AccountId*>(
      ::bgs::protocol::account::v1::AccountId::internal_default_instance());
}
class SubscribeNotification::_Internal {
 public:
  using HasBits = decltype(std::declval<SubscribeNotification>()._has_bits_);
  static const ::bgs::protocol::account::v1::AccountId& subscriber_id(const SubscribeNotification* msg);
  static void set_has_subscriber_id(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

const ::bgs::protocol::account::v1::AccountId&
SubscribeNotification::_Internal::subscriber_id(const SubscribeNotification* msg) {
  return *msg->subscriber_id_;
}
void SubscribeNotification::clear_subscriber_id() {
  if (subscriber_id_ != nullptr) subscriber_id_->Clear();
  _has_bits_[0] &= ~0x00000001u;
}
void SubscribeNotification::clear_state() {
  state_.Clear();
}
SubscribeNotification::SubscribeNotification()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.SubscribeNotification)
}
SubscribeNotification::SubscribeNotification(const SubscribeNotification& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      state_(from.state_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from._internal_has_subscriber_id()) {
    subscriber_id_ = new ::bgs::protocol::account::v1::AccountId(*from.subscriber_id_);
  } else {
    subscriber_id_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.SubscribeNotification)
}

void SubscribeNotification::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_SubscribeNotification_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto.base);
  subscriber_id_ = nullptr;
}

SubscribeNotification::~SubscribeNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.SubscribeNotification)
  SharedDtor();
}

void SubscribeNotification::SharedDtor() {
  if (this != internal_default_instance()) delete subscriber_id_;
}

void SubscribeNotification::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const SubscribeNotification& SubscribeNotification::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_SubscribeNotification_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto.base);
  return *internal_default_instance();
}


void SubscribeNotification::Clear() {
// @@protoc_insertion_point(message_clear_start:bgs.protocol.presence.v1.SubscribeNotification)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  state_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    GOOGLE_DCHECK(subscriber_id_ != nullptr);
    subscriber_id_->Clear();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* SubscribeNotification::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional .bgs.protocol.account.v1.AccountId subscriber_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_subscriber_id(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .bgs.protocol.presence.v1.PresenceState state = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_state(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* SubscribeNotification::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.SubscribeNotification)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .bgs.protocol.account.v1.AccountId subscriber_id = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::subscriber_id(this), target, stream);
  }

  // repeated .bgs.protocol.presence.v1.PresenceState state = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_state_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_state(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.SubscribeNotification)
  return target;
}

size_t SubscribeNotification::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:bgs.protocol.presence.v1.SubscribeNotification)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .bgs.protocol.presence.v1.PresenceState state = 2;
  total_size += 1UL * this->_internal_state_size();
  for (const auto& msg : this->state_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // optional .bgs.protocol.account.v1.AccountId subscriber_id = 1;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *subscriber_id_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SubscribeNotification::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:bgs.protocol.presence.v1.SubscribeNotification)
  GOOGLE_DCHECK_NE(&from, this);
  const SubscribeNotification* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<SubscribeNotification>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:bgs.protocol.presence.v1.SubscribeNotification)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:bgs.protocol.presence.v1.SubscribeNotification)
    MergeFrom(*source);
  }
}

void SubscribeNotification::MergeFrom(const SubscribeNotification& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:bgs.protocol.presence.v1.SubscribeNotification)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  state_.MergeFrom(from.state_);
  if (from._internal_has_subscriber_id()) {
    _internal_mutable_subscriber_id()->::bgs::protocol::account::v1::AccountId::MergeFrom(from._internal_subscriber_id());
  }
}

void SubscribeNotification::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:bgs.protocol.presence.v1.SubscribeNotification)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SubscribeNotification::CopyFrom(const SubscribeNotification& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:bgs.protocol.presence.v1.SubscribeNotification)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SubscribeNotification::IsInitialized() const {
  if (!::PROTOBUF_NAMESPACE_ID::internal::AllAreInitialized(state_)) return false;
  if (_internal_has_subscriber_id()) {
    if (!subscriber_id_->IsInitialized()) return false;
  }
  return true;
}

void SubscribeNotification::InternalSwap(SubscribeNotification* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  state_.InternalSwap(&other->state_);
  swap(subscriber_id_, other->subscriber_id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata SubscribeNotification::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void StateChangedNotification::InitAsDefaultInstance() {
  ::bgs::protocol::presence::v1::_StateChangedNotification_default_instance_._instance.get_mutable()->subscriber_id_ = const_cast< ::bgs::protocol::account::v1::AccountId*>(
      ::bgs::protocol::account::v1::AccountId::internal_default_instance());
}
class StateChangedNotification::_Internal {
 public:
  using HasBits = decltype(std::declval<StateChangedNotification>()._has_bits_);
  static const ::bgs::protocol::account::v1::AccountId& subscriber_id(const StateChangedNotification* msg);
  static void set_has_subscriber_id(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

const ::bgs::protocol::account::v1::AccountId&
StateChangedNotification::_Internal::subscriber_id(const StateChangedNotification* msg) {
  return *msg->subscriber_id_;
}
void StateChangedNotification::clear_subscriber_id() {
  if (subscriber_id_ != nullptr) subscriber_id_->Clear();
  _has_bits_[0] &= ~0x00000001u;
}
void StateChangedNotification::clear_state() {
  state_.Clear();
}
StateChangedNotification::StateChangedNotification()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.presence.v1.StateChangedNotification)
}
StateChangedNotification::StateChangedNotification(const StateChangedNotification& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      state_(from.state_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from._internal_has_subscriber_id()) {
    subscriber_id_ = new ::bgs::protocol::account::v1::AccountId(*from.subscriber_id_);
  } else {
    subscriber_id_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.presence.v1.StateChangedNotification)
}

void StateChangedNotification::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_StateChangedNotification_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto.base);
  subscriber_id_ = nullptr;
}

StateChangedNotification::~StateChangedNotification() {
  // @@protoc_insertion_point(destructor:bgs.protocol.presence.v1.StateChangedNotification)
  SharedDtor();
}

void StateChangedNotification::SharedDtor() {
  if (this != internal_default_instance()) delete subscriber_id_;
}

void StateChangedNotification::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const StateChangedNotification& StateChangedNotification::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_StateChangedNotification_bgs_2flow_2fpb_2fclient_2fpresence_5flistener_2eproto.base);
  return *internal_default_instance();
}


void StateChangedNotification::Clear() {
// @@protoc_insertion_point(message_clear_start:bgs.protocol.presence.v1.StateChangedNotification)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  state_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    GOOGLE_DCHECK(subscriber_id_ != nullptr);
    subscriber_id_->Clear();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* StateChangedNotification::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional .bgs.protocol.account.v1.AccountId subscriber_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_subscriber_id(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .bgs.protocol.presence.v1.PresenceState state = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_state(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* StateChangedNotification::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.presence.v1.StateChangedNotification)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .bgs.protocol.account.v1.AccountId subscriber_id = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::subscriber_id(this), target, stream);
  }

  // repeated .bgs.protocol.presence.v1.PresenceState state = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_state_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_state(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.presence.v1.StateChangedNotification)
  return target;
}

size_t StateChangedNotification::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:bgs.protocol.presence.v1.StateChangedNotification)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .bgs.protocol.presence.v1.PresenceState state = 2;
  total_size += 1UL * this->_internal_state_size();
  for (const auto& msg : this->state_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // optional .bgs.protocol.account.v1.AccountId subscriber_id = 1;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *subscriber_id_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void StateChangedNotification::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:bgs.protocol.presence.v1.StateChangedNotification)
  GOOGLE_DCHECK_NE(&from, this);
  const StateChangedNotification* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<StateChangedNotification>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:bgs.protocol.presence.v1.StateChangedNotification)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:bgs.protocol.presence.v1.StateChangedNotification)
    MergeFrom(*source);
  }
}

void StateChangedNotification::MergeFrom(const StateChangedNotification& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:bgs.protocol.presence.v1.StateChangedNotification)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  state_.MergeFrom(from.state_);
  if (from._internal_has_subscriber_id()) {
    _internal_mutable_subscriber_id()->::bgs::protocol::account::v1::AccountId::MergeFrom(from._internal_subscriber_id());
  }
}

void StateChangedNotification::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:bgs.protocol.presence.v1.StateChangedNotification)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void StateChangedNotification::CopyFrom(const StateChangedNotification& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:bgs.protocol.presence.v1.StateChangedNotification)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool StateChangedNotification::IsInitialized() const {
  if (!::PROTOBUF_NAMESPACE_ID::internal::AllAreInitialized(state_)) return false;
  if (_internal_has_subscriber_id()) {
    if (!subscriber_id_->IsInitialized()) return false;
  }
  return true;
}

void StateChangedNotification::InternalSwap(StateChangedNotification* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  state_.InternalSwap(&other->state_);
  swap(subscriber_id_, other->subscriber_id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata StateChangedNotification::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace v1
}  // namespace presence
}  // namespace protocol
}  // namespace bgs
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::bgs::protocol::presence::v1::SubscribeNotification* Arena::CreateMaybeMessage< ::bgs::protocol::presence::v1::SubscribeNotification >(Arena* arena) {
  return Arena::CreateInternal< ::bgs::protocol::presence::v1::SubscribeNotification >(arena);
}
template<> PROTOBUF_NOINLINE ::bgs::protocol::presence::v1::StateChangedNotification* Arena::CreateMaybeMessage< ::bgs::protocol::presence::v1::StateChangedNotification >(Arena* arena) {
  return Arena::CreateInternal< ::bgs::protocol::presence::v1::StateChangedNotification >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>