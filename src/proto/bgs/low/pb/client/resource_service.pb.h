// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bgs/low/pb/client/resource_service.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_bgs_2flow_2fpb_2fclient_2fresource_5fservice_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_bgs_2flow_2fpb_2fclient_2fresource_5fservice_2eproto

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
#include "bgs/low/pb/client/content_handle_types.pb.h"
#include "bgs/low/pb/client/rpc_types.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_bgs_2flow_2fpb_2fclient_2fresource_5fservice_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_bgs_2flow_2fpb_2fclient_2fresource_5fservice_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_bgs_2flow_2fpb_2fclient_2fresource_5fservice_2eproto;
namespace bgs {
namespace protocol {
namespace resources {
namespace v1 {
class ContentHandleRequest;
class ContentHandleRequestDefaultTypeInternal;
extern ContentHandleRequestDefaultTypeInternal _ContentHandleRequest_default_instance_;
}  // namespace v1
}  // namespace resources
}  // namespace protocol
}  // namespace bgs
PROTOBUF_NAMESPACE_OPEN
template<> ::bgs::protocol::resources::v1::ContentHandleRequest* Arena::CreateMaybeMessage<::bgs::protocol::resources::v1::ContentHandleRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace bgs {
namespace protocol {
namespace resources {
namespace v1 {

// ===================================================================

class ContentHandleRequest :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:bgs.protocol.resources.v1.ContentHandleRequest) */ {
 public:
  ContentHandleRequest();
  virtual ~ContentHandleRequest();

  ContentHandleRequest(const ContentHandleRequest& from);
  ContentHandleRequest(ContentHandleRequest&& from) noexcept
    : ContentHandleRequest() {
    *this = ::std::move(from);
  }

  inline ContentHandleRequest& operator=(const ContentHandleRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline ContentHandleRequest& operator=(ContentHandleRequest&& from) noexcept {
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
  static const ContentHandleRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ContentHandleRequest* internal_default_instance() {
    return reinterpret_cast<const ContentHandleRequest*>(
               &_ContentHandleRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ContentHandleRequest& a, ContentHandleRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(ContentHandleRequest* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ContentHandleRequest* New() const final {
    return CreateMaybeMessage<ContentHandleRequest>(nullptr);
  }

  ContentHandleRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ContentHandleRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ContentHandleRequest& from);
  void MergeFrom(const ContentHandleRequest& from);
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
  void InternalSwap(ContentHandleRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "bgs.protocol.resources.v1.ContentHandleRequest";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_bgs_2flow_2fpb_2fclient_2fresource_5fservice_2eproto);
    return ::descriptor_table_bgs_2flow_2fpb_2fclient_2fresource_5fservice_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kProgramFieldNumber = 1,
    kStreamFieldNumber = 2,
    kVersionFieldNumber = 3,
  };
  // required fixed32 program = 1;
  bool has_program() const;
  private:
  bool _internal_has_program() const;
  public:
  void clear_program();
  ::PROTOBUF_NAMESPACE_ID::uint32 program() const;
  void set_program(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_program() const;
  void _internal_set_program(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // required fixed32 stream = 2;
  bool has_stream() const;
  private:
  bool _internal_has_stream() const;
  public:
  void clear_stream();
  ::PROTOBUF_NAMESPACE_ID::uint32 stream() const;
  void set_stream(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_stream() const;
  void _internal_set_stream(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // optional fixed32 version = 3 [default = 1701729619];
  bool has_version() const;
  private:
  bool _internal_has_version() const;
  public:
  void clear_version();
  ::PROTOBUF_NAMESPACE_ID::uint32 version() const;
  void set_version(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_version() const;
  void _internal_set_version(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:bgs.protocol.resources.v1.ContentHandleRequest)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::uint32 program_;
  ::PROTOBUF_NAMESPACE_ID::uint32 stream_;
  ::PROTOBUF_NAMESPACE_ID::uint32 version_;
  friend struct ::TableStruct_bgs_2flow_2fpb_2fclient_2fresource_5fservice_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ContentHandleRequest

// required fixed32 program = 1;
inline bool ContentHandleRequest::_internal_has_program() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool ContentHandleRequest::has_program() const {
  return _internal_has_program();
}
inline void ContentHandleRequest::clear_program() {
  program_ = 0u;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ContentHandleRequest::_internal_program() const {
  return program_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ContentHandleRequest::program() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.resources.v1.ContentHandleRequest.program)
  return _internal_program();
}
inline void ContentHandleRequest::_internal_set_program(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000001u;
  program_ = value;
}
inline void ContentHandleRequest::set_program(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_program(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.resources.v1.ContentHandleRequest.program)
}

// required fixed32 stream = 2;
inline bool ContentHandleRequest::_internal_has_stream() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool ContentHandleRequest::has_stream() const {
  return _internal_has_stream();
}
inline void ContentHandleRequest::clear_stream() {
  stream_ = 0u;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ContentHandleRequest::_internal_stream() const {
  return stream_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ContentHandleRequest::stream() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.resources.v1.ContentHandleRequest.stream)
  return _internal_stream();
}
inline void ContentHandleRequest::_internal_set_stream(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000002u;
  stream_ = value;
}
inline void ContentHandleRequest::set_stream(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_stream(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.resources.v1.ContentHandleRequest.stream)
}

// optional fixed32 version = 3 [default = 1701729619];
inline bool ContentHandleRequest::_internal_has_version() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool ContentHandleRequest::has_version() const {
  return _internal_has_version();
}
inline void ContentHandleRequest::clear_version() {
  version_ = 1701729619u;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ContentHandleRequest::_internal_version() const {
  return version_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ContentHandleRequest::version() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.resources.v1.ContentHandleRequest.version)
  return _internal_version();
}
inline void ContentHandleRequest::_internal_set_version(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000004u;
  version_ = value;
}
inline void ContentHandleRequest::set_version(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_version(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.resources.v1.ContentHandleRequest.version)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace resources
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_bgs_2flow_2fpb_2fclient_2fresource_5fservice_2eproto
