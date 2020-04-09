// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bgs/low/pb/client/user_manager_types.proto

#include "bgs/low/pb/client/user_manager_types.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_bgs_2flow_2fpb_2fclient_2fattribute_5ftypes_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Attribute_bgs_2flow_2fpb_2fclient_2fattribute_5ftypes_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_bgs_2flow_2fpb_2fclient_2fentity_5ftypes_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_EntityId_bgs_2flow_2fpb_2fclient_2fentity_5ftypes_2eproto;
namespace bgs {
namespace protocol {
namespace user_manager {
namespace v1 {
class RecentPlayerDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<RecentPlayer> _instance;
} _RecentPlayer_default_instance_;
class BlockedPlayerDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<BlockedPlayer> _instance;
} _BlockedPlayer_default_instance_;
}  // namespace v1
}  // namespace user_manager
}  // namespace protocol
}  // namespace bgs
static void InitDefaultsscc_info_BlockedPlayer_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::bgs::protocol::user_manager::v1::_BlockedPlayer_default_instance_;
    new (ptr) ::bgs::protocol::user_manager::v1::BlockedPlayer();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::bgs::protocol::user_manager::v1::BlockedPlayer::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_BlockedPlayer_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_BlockedPlayer_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto}, {
      &scc_info_EntityId_bgs_2flow_2fpb_2fclient_2fentity_5ftypes_2eproto.base,}};

static void InitDefaultsscc_info_RecentPlayer_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::bgs::protocol::user_manager::v1::_RecentPlayer_default_instance_;
    new (ptr) ::bgs::protocol::user_manager::v1::RecentPlayer();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::bgs::protocol::user_manager::v1::RecentPlayer::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_RecentPlayer_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_RecentPlayer_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto}, {
      &scc_info_EntityId_bgs_2flow_2fpb_2fclient_2fentity_5ftypes_2eproto.base,
      &scc_info_Attribute_bgs_2flow_2fpb_2fclient_2fattribute_5ftypes_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::user_manager::v1::RecentPlayer, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::user_manager::v1::RecentPlayer, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::user_manager::v1::RecentPlayer, entity_id_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::user_manager::v1::RecentPlayer, program_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::user_manager::v1::RecentPlayer, timestamp_played_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::user_manager::v1::RecentPlayer, attributes_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::user_manager::v1::RecentPlayer, id_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::user_manager::v1::RecentPlayer, counter_),
  1,
  0,
  2,
  ~0u,
  3,
  4,
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::user_manager::v1::BlockedPlayer, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::user_manager::v1::BlockedPlayer, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::user_manager::v1::BlockedPlayer, account_id_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::user_manager::v1::BlockedPlayer, name_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::user_manager::v1::BlockedPlayer, role_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::user_manager::v1::BlockedPlayer, privileges_),
  1,
  0,
  ~0u,
  2,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 11, sizeof(::bgs::protocol::user_manager::v1::RecentPlayer)},
  { 17, 26, sizeof(::bgs::protocol::user_manager::v1::BlockedPlayer)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::bgs::protocol::user_manager::v1::_RecentPlayer_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::bgs::protocol::user_manager::v1::_BlockedPlayer_default_instance_),
};

const char descriptor_table_protodef_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n*bgs/low/pb/client/user_manager_types.p"
  "roto\022\034bgs.protocol.user_manager.v1\032$bgs/"
  "low/pb/client/entity_types.proto\032\'bgs/lo"
  "w/pb/client/attribute_types.proto\"\264\001\n\014Re"
  "centPlayer\022)\n\tentity_id\030\001 \002(\0132\026.bgs.prot"
  "ocol.EntityId\022\017\n\007program\030\002 \001(\t\022\030\n\020timest"
  "amp_played\030\003 \001(\006\022+\n\nattributes\030\004 \003(\0132\027.b"
  "gs.protocol.Attribute\022\r\n\002id\030\005 \001(\007:\0010\022\022\n\007"
  "counter\030\006 \001(\007:\0010\"r\n\rBlockedPlayer\022*\n\nacc"
  "ount_id\030\001 \002(\0132\026.bgs.protocol.EntityId\022\014\n"
  "\004name\030\002 \001(\t\022\020\n\004role\030\003 \003(\rB\002\020\001\022\025\n\nprivile"
  "ges\030\004 \001(\004:\0010"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto_deps[2] = {
  &::descriptor_table_bgs_2flow_2fpb_2fclient_2fattribute_5ftypes_2eproto,
  &::descriptor_table_bgs_2flow_2fpb_2fclient_2fentity_5ftypes_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto_sccs[2] = {
  &scc_info_BlockedPlayer_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto.base,
  &scc_info_RecentPlayer_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto_once;
static bool descriptor_table_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto = {
  &descriptor_table_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto_initialized, descriptor_table_protodef_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto, "bgs/low/pb/client/user_manager_types.proto", 452,
  &descriptor_table_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto_once, descriptor_table_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto_sccs, descriptor_table_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto_deps, 2, 2,
  schemas, file_default_instances, TableStruct_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto::offsets,
  file_level_metadata_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto, 2, file_level_enum_descriptors_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto, file_level_service_descriptors_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto)), true);
namespace bgs {
namespace protocol {
namespace user_manager {
namespace v1 {

// ===================================================================

void RecentPlayer::InitAsDefaultInstance() {
  ::bgs::protocol::user_manager::v1::_RecentPlayer_default_instance_._instance.get_mutable()->entity_id_ = const_cast< ::bgs::protocol::EntityId*>(
      ::bgs::protocol::EntityId::internal_default_instance());
}
class RecentPlayer::_Internal {
 public:
  using HasBits = decltype(std::declval<RecentPlayer>()._has_bits_);
  static const ::bgs::protocol::EntityId& entity_id(const RecentPlayer* msg);
  static void set_has_entity_id(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_program(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_timestamp_played(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_id(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_counter(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
};

const ::bgs::protocol::EntityId&
RecentPlayer::_Internal::entity_id(const RecentPlayer* msg) {
  return *msg->entity_id_;
}
void RecentPlayer::clear_entity_id() {
  if (entity_id_ != nullptr) entity_id_->Clear();
  _has_bits_[0] &= ~0x00000002u;
}
void RecentPlayer::clear_attributes() {
  attributes_.Clear();
}
RecentPlayer::RecentPlayer()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.RecentPlayer)
}
RecentPlayer::RecentPlayer(const RecentPlayer& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      attributes_(from.attributes_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  program_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_program()) {
    program_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.program_);
  }
  if (from._internal_has_entity_id()) {
    entity_id_ = new ::bgs::protocol::EntityId(*from.entity_id_);
  } else {
    entity_id_ = nullptr;
  }
  ::memcpy(&timestamp_played_, &from.timestamp_played_,
    static_cast<size_t>(reinterpret_cast<char*>(&counter_) -
    reinterpret_cast<char*>(&timestamp_played_)) + sizeof(counter_));
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.RecentPlayer)
}

void RecentPlayer::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_RecentPlayer_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto.base);
  program_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&entity_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&counter_) -
      reinterpret_cast<char*>(&entity_id_)) + sizeof(counter_));
}

RecentPlayer::~RecentPlayer() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.RecentPlayer)
  SharedDtor();
}

void RecentPlayer::SharedDtor() {
  program_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete entity_id_;
}

void RecentPlayer::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const RecentPlayer& RecentPlayer::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_RecentPlayer_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto.base);
  return *internal_default_instance();
}


void RecentPlayer::Clear() {
// @@protoc_insertion_point(message_clear_start:bgs.protocol.user_manager.v1.RecentPlayer)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  attributes_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      program_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(entity_id_ != nullptr);
      entity_id_->Clear();
    }
  }
  if (cached_has_bits & 0x0000001cu) {
    ::memset(&timestamp_played_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&counter_) -
        reinterpret_cast<char*>(&timestamp_played_)) + sizeof(counter_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* RecentPlayer::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required .bgs.protocol.EntityId entity_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_entity_id(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string program = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_program();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "bgs.protocol.user_manager.v1.RecentPlayer.program");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional fixed64 timestamp_played = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 25)) {
          _Internal::set_has_timestamp_played(&has_bits);
          timestamp_played_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint64>(ptr);
          ptr += sizeof(::PROTOBUF_NAMESPACE_ID::uint64);
        } else goto handle_unusual;
        continue;
      // repeated .bgs.protocol.Attribute attributes = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_attributes(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<34>(ptr));
        } else goto handle_unusual;
        continue;
      // optional fixed32 id = 5 [default = 0];
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 45)) {
          _Internal::set_has_id(&has_bits);
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint32>(ptr);
          ptr += sizeof(::PROTOBUF_NAMESPACE_ID::uint32);
        } else goto handle_unusual;
        continue;
      // optional fixed32 counter = 6 [default = 0];
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 53)) {
          _Internal::set_has_counter(&has_bits);
          counter_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint32>(ptr);
          ptr += sizeof(::PROTOBUF_NAMESPACE_ID::uint32);
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

::PROTOBUF_NAMESPACE_ID::uint8* RecentPlayer::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.RecentPlayer)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .bgs.protocol.EntityId entity_id = 1;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::entity_id(this), target, stream);
  }

  // optional string program = 2;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_program().data(), static_cast<int>(this->_internal_program().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "bgs.protocol.user_manager.v1.RecentPlayer.program");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_program(), target);
  }

  // optional fixed64 timestamp_played = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFixed64ToArray(3, this->_internal_timestamp_played(), target);
  }

  // repeated .bgs.protocol.Attribute attributes = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_attributes_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(4, this->_internal_attributes(i), target, stream);
  }

  // optional fixed32 id = 5 [default = 0];
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFixed32ToArray(5, this->_internal_id(), target);
  }

  // optional fixed32 counter = 6 [default = 0];
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFixed32ToArray(6, this->_internal_counter(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.RecentPlayer)
  return target;
}

size_t RecentPlayer::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:bgs.protocol.user_manager.v1.RecentPlayer)
  size_t total_size = 0;

  // required .bgs.protocol.EntityId entity_id = 1;
  if (_internal_has_entity_id()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *entity_id_);
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .bgs.protocol.Attribute attributes = 4;
  total_size += 1UL * this->_internal_attributes_size();
  for (const auto& msg : this->attributes_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // optional string program = 2;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_program());
  }

  if (cached_has_bits & 0x0000001cu) {
    // optional fixed64 timestamp_played = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 + 8;
    }

    // optional fixed32 id = 5 [default = 0];
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 + 4;
    }

    // optional fixed32 counter = 6 [default = 0];
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 + 4;
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RecentPlayer::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:bgs.protocol.user_manager.v1.RecentPlayer)
  GOOGLE_DCHECK_NE(&from, this);
  const RecentPlayer* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<RecentPlayer>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:bgs.protocol.user_manager.v1.RecentPlayer)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:bgs.protocol.user_manager.v1.RecentPlayer)
    MergeFrom(*source);
  }
}

void RecentPlayer::MergeFrom(const RecentPlayer& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:bgs.protocol.user_manager.v1.RecentPlayer)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  attributes_.MergeFrom(from.attributes_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      program_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.program_);
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_mutable_entity_id()->::bgs::protocol::EntityId::MergeFrom(from._internal_entity_id());
    }
    if (cached_has_bits & 0x00000004u) {
      timestamp_played_ = from.timestamp_played_;
    }
    if (cached_has_bits & 0x00000008u) {
      id_ = from.id_;
    }
    if (cached_has_bits & 0x00000010u) {
      counter_ = from.counter_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void RecentPlayer::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:bgs.protocol.user_manager.v1.RecentPlayer)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RecentPlayer::CopyFrom(const RecentPlayer& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:bgs.protocol.user_manager.v1.RecentPlayer)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RecentPlayer::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;
  if (!::PROTOBUF_NAMESPACE_ID::internal::AllAreInitialized(attributes_)) return false;
  if (_internal_has_entity_id()) {
    if (!entity_id_->IsInitialized()) return false;
  }
  return true;
}

void RecentPlayer::InternalSwap(RecentPlayer* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  attributes_.InternalSwap(&other->attributes_);
  program_.Swap(&other->program_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(entity_id_, other->entity_id_);
  swap(timestamp_played_, other->timestamp_played_);
  swap(id_, other->id_);
  swap(counter_, other->counter_);
}

::PROTOBUF_NAMESPACE_ID::Metadata RecentPlayer::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void BlockedPlayer::InitAsDefaultInstance() {
  ::bgs::protocol::user_manager::v1::_BlockedPlayer_default_instance_._instance.get_mutable()->account_id_ = const_cast< ::bgs::protocol::EntityId*>(
      ::bgs::protocol::EntityId::internal_default_instance());
}
class BlockedPlayer::_Internal {
 public:
  using HasBits = decltype(std::declval<BlockedPlayer>()._has_bits_);
  static const ::bgs::protocol::EntityId& account_id(const BlockedPlayer* msg);
  static void set_has_account_id(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_privileges(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
};

const ::bgs::protocol::EntityId&
BlockedPlayer::_Internal::account_id(const BlockedPlayer* msg) {
  return *msg->account_id_;
}
void BlockedPlayer::clear_account_id() {
  if (account_id_ != nullptr) account_id_->Clear();
  _has_bits_[0] &= ~0x00000002u;
}
BlockedPlayer::BlockedPlayer()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.user_manager.v1.BlockedPlayer)
}
BlockedPlayer::BlockedPlayer(const BlockedPlayer& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      role_(from.role_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_name()) {
    name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  if (from._internal_has_account_id()) {
    account_id_ = new ::bgs::protocol::EntityId(*from.account_id_);
  } else {
    account_id_ = nullptr;
  }
  privileges_ = from.privileges_;
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.user_manager.v1.BlockedPlayer)
}

void BlockedPlayer::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_BlockedPlayer_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&account_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&privileges_) -
      reinterpret_cast<char*>(&account_id_)) + sizeof(privileges_));
}

BlockedPlayer::~BlockedPlayer() {
  // @@protoc_insertion_point(destructor:bgs.protocol.user_manager.v1.BlockedPlayer)
  SharedDtor();
}

void BlockedPlayer::SharedDtor() {
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete account_id_;
}

void BlockedPlayer::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const BlockedPlayer& BlockedPlayer::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_BlockedPlayer_bgs_2flow_2fpb_2fclient_2fuser_5fmanager_5ftypes_2eproto.base);
  return *internal_default_instance();
}


void BlockedPlayer::Clear() {
// @@protoc_insertion_point(message_clear_start:bgs.protocol.user_manager.v1.BlockedPlayer)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  role_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      name_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(account_id_ != nullptr);
      account_id_->Clear();
    }
  }
  privileges_ = PROTOBUF_ULONGLONG(0);
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* BlockedPlayer::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required .bgs.protocol.EntityId account_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_account_id(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "bgs.protocol.user_manager.v1.BlockedPlayer.name");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated uint32 role = 3 [packed = true];
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedUInt32Parser(_internal_mutable_role(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24) {
          _internal_add_role(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional uint64 privileges = 4 [default = 0];
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          _Internal::set_has_privileges(&has_bits);
          privileges_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* BlockedPlayer::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.user_manager.v1.BlockedPlayer)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .bgs.protocol.EntityId account_id = 1;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::account_id(this), target, stream);
  }

  // optional string name = 2;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "bgs.protocol.user_manager.v1.BlockedPlayer.name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_name(), target);
  }

  // repeated uint32 role = 3 [packed = true];
  {
    int byte_size = _role_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteUInt32Packed(
          3, _internal_role(), byte_size, target);
    }
  }

  // optional uint64 privileges = 4 [default = 0];
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(4, this->_internal_privileges(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.user_manager.v1.BlockedPlayer)
  return target;
}

size_t BlockedPlayer::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:bgs.protocol.user_manager.v1.BlockedPlayer)
  size_t total_size = 0;

  // required .bgs.protocol.EntityId account_id = 1;
  if (_internal_has_account_id()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *account_id_);
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated uint32 role = 3 [packed = true];
  {
    size_t data_size = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      UInt32Size(this->role_);
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<::PROTOBUF_NAMESPACE_ID::int32>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _role_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // optional string name = 2;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // optional uint64 privileges = 4 [default = 0];
  if (cached_has_bits & 0x00000004u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_privileges());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void BlockedPlayer::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:bgs.protocol.user_manager.v1.BlockedPlayer)
  GOOGLE_DCHECK_NE(&from, this);
  const BlockedPlayer* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<BlockedPlayer>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:bgs.protocol.user_manager.v1.BlockedPlayer)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:bgs.protocol.user_manager.v1.BlockedPlayer)
    MergeFrom(*source);
  }
}

void BlockedPlayer::MergeFrom(const BlockedPlayer& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:bgs.protocol.user_manager.v1.BlockedPlayer)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  role_.MergeFrom(from.role_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.name_);
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_mutable_account_id()->::bgs::protocol::EntityId::MergeFrom(from._internal_account_id());
    }
    if (cached_has_bits & 0x00000004u) {
      privileges_ = from.privileges_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void BlockedPlayer::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:bgs.protocol.user_manager.v1.BlockedPlayer)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BlockedPlayer::CopyFrom(const BlockedPlayer& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:bgs.protocol.user_manager.v1.BlockedPlayer)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BlockedPlayer::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;
  if (_internal_has_account_id()) {
    if (!account_id_->IsInitialized()) return false;
  }
  return true;
}

void BlockedPlayer::InternalSwap(BlockedPlayer* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  role_.InternalSwap(&other->role_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(account_id_, other->account_id_);
  swap(privileges_, other->privileges_);
}

::PROTOBUF_NAMESPACE_ID::Metadata BlockedPlayer::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace v1
}  // namespace user_manager
}  // namespace protocol
}  // namespace bgs
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::bgs::protocol::user_manager::v1::RecentPlayer* Arena::CreateMaybeMessage< ::bgs::protocol::user_manager::v1::RecentPlayer >(Arena* arena) {
  return Arena::CreateInternal< ::bgs::protocol::user_manager::v1::RecentPlayer >(arena);
}
template<> PROTOBUF_NOINLINE ::bgs::protocol::user_manager::v1::BlockedPlayer* Arena::CreateMaybeMessage< ::bgs::protocol::user_manager::v1::BlockedPlayer >(Arena* arena) {
  return Arena::CreateInternal< ::bgs::protocol::user_manager::v1::BlockedPlayer >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>