// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bgs/low/pb/client/api/client/v1/channel_id.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "bgs/low/pb/client/rpc_types.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto;
namespace bgs {
namespace protocol {
namespace channel {
namespace v1 {
class ChannelId;
class ChannelIdDefaultTypeInternal;
extern ChannelIdDefaultTypeInternal _ChannelId_default_instance_;
}  // namespace v1
}  // namespace channel
}  // namespace protocol
}  // namespace bgs
PROTOBUF_NAMESPACE_OPEN
template<> ::bgs::protocol::channel::v1::ChannelId* Arena::CreateMaybeMessage<::bgs::protocol::channel::v1::ChannelId>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace bgs {
namespace protocol {
namespace channel {
namespace v1 {

// ===================================================================

class ChannelId :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:bgs.protocol.channel.v1.ChannelId) */ {
 public:
  ChannelId();
  virtual ~ChannelId();

  ChannelId(const ChannelId& from);
  ChannelId(ChannelId&& from) noexcept
    : ChannelId() {
    *this = ::std::move(from);
  }

  inline ChannelId& operator=(const ChannelId& from) {
    CopyFrom(from);
    return *this;
  }
  inline ChannelId& operator=(ChannelId&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ChannelId& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ChannelId* internal_default_instance() {
    return reinterpret_cast<const ChannelId*>(
               &_ChannelId_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ChannelId& a, ChannelId& b) {
    a.Swap(&b);
  }
  inline void Swap(ChannelId* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ChannelId* New() const final {
    return CreateMaybeMessage<ChannelId>(nullptr);
  }

  ChannelId* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ChannelId>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ChannelId& from);
  void MergeFrom(const ChannelId& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ChannelId* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "bgs.protocol.channel.v1.ChannelId";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto);
    return ::descriptor_table_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kHostFieldNumber = 2,
    kTypeFieldNumber = 1,
    kIdFieldNumber = 3,
  };
  // optional .bgs.protocol.ProcessId host = 2;
  bool has_host() const;
  private:
  bool _internal_has_host() const;
  public:
  void clear_host();
  const ::bgs::protocol::ProcessId& host() const;
  ::bgs::protocol::ProcessId* release_host();
  ::bgs::protocol::ProcessId* mutable_host();
  void set_allocated_host(::bgs::protocol::ProcessId* host);
  private:
  const ::bgs::protocol::ProcessId& _internal_host() const;
  ::bgs::protocol::ProcessId* _internal_mutable_host();
  public:

  // optional uint32 type = 1;
  bool has_type() const;
  private:
  bool _internal_has_type() const;
  public:
  void clear_type();
  ::PROTOBUF_NAMESPACE_ID::uint32 type() const;
  void set_type(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_type() const;
  void _internal_set_type(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // optional fixed32 id = 3;
  bool has_id() const;
  private:
  bool _internal_has_id() const;
  public:
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::uint32 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:bgs.protocol.channel.v1.ChannelId)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::bgs::protocol::ProcessId* host_;
  ::PROTOBUF_NAMESPACE_ID::uint32 type_;
  ::PROTOBUF_NAMESPACE_ID::uint32 id_;
  friend struct ::TableStruct_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ChannelId

// optional uint32 type = 1;
inline bool ChannelId::_internal_has_type() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool ChannelId::has_type() const {
  return _internal_has_type();
}
inline void ChannelId::clear_type() {
  type_ = 0u;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ChannelId::_internal_type() const {
  return type_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ChannelId::type() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.channel.v1.ChannelId.type)
  return _internal_type();
}
inline void ChannelId::_internal_set_type(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000002u;
  type_ = value;
}
inline void ChannelId::set_type(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.channel.v1.ChannelId.type)
}

// optional .bgs.protocol.ProcessId host = 2;
inline bool ChannelId::_internal_has_host() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || host_ != nullptr);
  return value;
}
inline bool ChannelId::has_host() const {
  return _internal_has_host();
}
inline const ::bgs::protocol::ProcessId& ChannelId::_internal_host() const {
  const ::bgs::protocol::ProcessId* p = host_;
  return p != nullptr ? *p : *reinterpret_cast<const ::bgs::protocol::ProcessId*>(
      &::bgs::protocol::_ProcessId_default_instance_);
}
inline const ::bgs::protocol::ProcessId& ChannelId::host() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.channel.v1.ChannelId.host)
  return _internal_host();
}
inline ::bgs::protocol::ProcessId* ChannelId::release_host() {
  // @@protoc_insertion_point(field_release:bgs.protocol.channel.v1.ChannelId.host)
  _has_bits_[0] &= ~0x00000001u;
  ::bgs::protocol::ProcessId* temp = host_;
  host_ = nullptr;
  return temp;
}
inline ::bgs::protocol::ProcessId* ChannelId::_internal_mutable_host() {
  _has_bits_[0] |= 0x00000001u;
  if (host_ == nullptr) {
    auto* p = CreateMaybeMessage<::bgs::protocol::ProcessId>(GetArenaNoVirtual());
    host_ = p;
  }
  return host_;
}
inline ::bgs::protocol::ProcessId* ChannelId::mutable_host() {
  // @@protoc_insertion_point(field_mutable:bgs.protocol.channel.v1.ChannelId.host)
  return _internal_mutable_host();
}
inline void ChannelId::set_allocated_host(::bgs::protocol::ProcessId* host) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(host_);
  }
  if (host) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      host = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, host, submessage_arena);
    }
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  host_ = host;
  // @@protoc_insertion_point(field_set_allocated:bgs.protocol.channel.v1.ChannelId.host)
}

// optional fixed32 id = 3;
inline bool ChannelId::_internal_has_id() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool ChannelId::has_id() const {
  return _internal_has_id();
}
inline void ChannelId::clear_id() {
  id_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ChannelId::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ChannelId::id() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.channel.v1.ChannelId.id)
  return _internal_id();
}
inline void ChannelId::_internal_set_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000004u;
  id_ = value;
}
inline void ChannelId::set_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.channel.v1.ChannelId.id)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace channel
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_bgs_2flow_2fpb_2fclient_2fapi_2fclient_2fv1_2fchannel_5fid_2eproto
