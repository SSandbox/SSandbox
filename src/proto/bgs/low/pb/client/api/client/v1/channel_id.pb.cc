// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bgs/low/pb/client/api/client/v1/channel_id.proto

#include "bgs/low/pb/client/api/client/v1/channel_id.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_bgs_2flow_2fpb_2fclient_2frpc_5ftypes_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ProcessId_bgs_2flow_2fpb_2fclient_2frpc_5ftypes_2eproto;
namespace bgs {
namespace protocol {
namespace channel {
namespace v1 {
class ChannelIdDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ChannelId> _instance;
} _ChannelId_default_instance_;
}  // namespace v1
}  // namespace channel
}  // namespace protocol
}  // namespace bgs
static void InitDefaultsscc_info_ChannelId_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::bgs::protocol::channel::v1::_ChannelId_default_instance_;
    new (ptr) ::bgs::protocol::channel::v1::ChannelId();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::bgs::protocol::channel::v1::ChannelId::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_ChannelId_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_ChannelId_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto}, {
      &scc_info_ProcessId_bgs_2flow_2fpb_2fclient_2frpc_5ftypes_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::channel::v1::ChannelId, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::channel::v1::ChannelId, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::channel::v1::ChannelId, type_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::channel::v1::ChannelId, host_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::channel::v1::ChannelId, id_),
  1,
  0,
  2,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, sizeof(::bgs::protocol::channel::v1::ChannelId)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::bgs::protocol::channel::v1::_ChannelId_default_instance_),
};

const char descriptor_table_protodef_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n0bgs/low/pb/client/api/client/v1/channe"
  "l_id.proto\022\027bgs.protocol.channel.v1\032!bgs"
  "/low/pb/client/rpc_types.proto\"T\n\tChanne"
  "lId\022\014\n\004type\030\001 \001(\r\022%\n\004host\030\002 \001(\0132\027.bgs.pr"
  "otocol.ProcessId\022\n\n\002id\030\003 \001(\007:\006\202\371+\002\010\001"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto_deps[1] = {
  &::descriptor_table_bgs_2flow_2fpb_2fclient_2frpc_5ftypes_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto_sccs[1] = {
  &scc_info_ChannelId_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto_once;
static bool descriptor_table_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto = {
  &descriptor_table_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto_initialized, descriptor_table_protodef_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto, "bgs/low/pb/client/api/client/v1/channel_id.proto", 196,
  &descriptor_table_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto_once, descriptor_table_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto_sccs, descriptor_table_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto::offsets,
  file_level_metadata_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto, 1, file_level_enum_descriptors_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto, file_level_service_descriptors_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto)), true);
namespace bgs {
namespace protocol {
namespace channel {
namespace v1 {

// ===================================================================

void ChannelId::InitAsDefaultInstance() {
  ::bgs::protocol::channel::v1::_ChannelId_default_instance_._instance.get_mutable()->host_ = const_cast< ::bgs::protocol::ProcessId*>(
      ::bgs::protocol::ProcessId::internal_default_instance());
}
class ChannelId::_Internal {
 public:
  using HasBits = decltype(std::declval<ChannelId>()._has_bits_);
  static void set_has_type(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static const ::bgs::protocol::ProcessId& host(const ChannelId* msg);
  static void set_has_host(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_id(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
};

const ::bgs::protocol::ProcessId&
ChannelId::_Internal::host(const ChannelId* msg) {
  return *msg->host_;
}
void ChannelId::clear_host() {
  if (host_ != nullptr) host_->Clear();
  _has_bits_[0] &= ~0x00000001u;
}
ChannelId::ChannelId()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.channel.v1.ChannelId)
}
ChannelId::ChannelId(const ChannelId& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from._internal_has_host()) {
    host_ = new ::bgs::protocol::ProcessId(*from.host_);
  } else {
    host_ = nullptr;
  }
  ::memcpy(&type_, &from.type_,
    static_cast<size_t>(reinterpret_cast<char*>(&id_) -
    reinterpret_cast<char*>(&type_)) + sizeof(id_));
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.channel.v1.ChannelId)
}

void ChannelId::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ChannelId_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto.base);
  ::memset(&host_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&id_) -
      reinterpret_cast<char*>(&host_)) + sizeof(id_));
}

ChannelId::~ChannelId() {
  // @@protoc_insertion_point(destructor:bgs.protocol.channel.v1.ChannelId)
  SharedDtor();
}

void ChannelId::SharedDtor() {
  if (this != internal_default_instance()) delete host_;
}

void ChannelId::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ChannelId& ChannelId::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ChannelId_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto.base);
  return *internal_default_instance();
}


void ChannelId::Clear() {
// @@protoc_insertion_point(message_clear_start:bgs.protocol.channel.v1.ChannelId)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    GOOGLE_DCHECK(host_ != nullptr);
    host_->Clear();
  }
  if (cached_has_bits & 0x00000006u) {
    ::memset(&type_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&id_) -
        reinterpret_cast<char*>(&type_)) + sizeof(id_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* ChannelId::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional uint32 type = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_type(&has_bits);
          type_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .bgs.protocol.ProcessId host = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_host(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional fixed32 id = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 29)) {
          _Internal::set_has_id(&has_bits);
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint32>(ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* ChannelId::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.channel.v1.ChannelId)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional uint32 type = 1;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_type(), target);
  }

  // optional .bgs.protocol.ProcessId host = 2;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        2, _Internal::host(this), target, stream);
  }

  // optional fixed32 id = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFixed32ToArray(3, this->_internal_id(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.channel.v1.ChannelId)
  return target;
}

size_t ChannelId::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:bgs.protocol.channel.v1.ChannelId)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    // optional .bgs.protocol.ProcessId host = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *host_);
    }

    // optional uint32 type = 1;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_type());
    }

    // optional fixed32 id = 3;
    if (cached_has_bits & 0x00000004u) {
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

void ChannelId::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:bgs.protocol.channel.v1.ChannelId)
  GOOGLE_DCHECK_NE(&from, this);
  const ChannelId* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ChannelId>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:bgs.protocol.channel.v1.ChannelId)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:bgs.protocol.channel.v1.ChannelId)
    MergeFrom(*source);
  }
}

void ChannelId::MergeFrom(const ChannelId& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:bgs.protocol.channel.v1.ChannelId)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_mutable_host()->::bgs::protocol::ProcessId::MergeFrom(from._internal_host());
    }
    if (cached_has_bits & 0x00000002u) {
      type_ = from.type_;
    }
    if (cached_has_bits & 0x00000004u) {
      id_ = from.id_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ChannelId::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:bgs.protocol.channel.v1.ChannelId)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChannelId::CopyFrom(const ChannelId& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:bgs.protocol.channel.v1.ChannelId)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChannelId::IsInitialized() const {
  if (_internal_has_host()) {
    if (!host_->IsInitialized()) return false;
  }
  return true;
}

void ChannelId::InternalSwap(ChannelId* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(host_, other->host_);
  swap(type_, other->type_);
  swap(id_, other->id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ChannelId::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace v1
}  // namespace channel
}  // namespace protocol
}  // namespace bgs
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::bgs::protocol::channel::v1::ChannelId* Arena::CreateMaybeMessage< ::bgs::protocol::channel::v1::ChannelId >(Arena* arena) {
  return Arena::CreateInternal< ::bgs::protocol::channel::v1::ChannelId >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
