// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bgs/low/pb/client/global_extensions/service_options.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fservice_5foptions_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fservice_5foptions_2eproto

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
#include <google/protobuf/descriptor.pb.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fservice_5foptions_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fservice_5foptions_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fservice_5foptions_2eproto;
namespace bgs {
namespace protocol {
class BGSServiceOptions;
class BGSServiceOptionsDefaultTypeInternal;
extern BGSServiceOptionsDefaultTypeInternal _BGSServiceOptions_default_instance_;
class SDKServiceOptions;
class SDKServiceOptionsDefaultTypeInternal;
extern SDKServiceOptionsDefaultTypeInternal _SDKServiceOptions_default_instance_;
}  // namespace protocol
}  // namespace bgs
PROTOBUF_NAMESPACE_OPEN
template<> ::bgs::protocol::BGSServiceOptions* Arena::CreateMaybeMessage<::bgs::protocol::BGSServiceOptions>(Arena*);
template<> ::bgs::protocol::SDKServiceOptions* Arena::CreateMaybeMessage<::bgs::protocol::SDKServiceOptions>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace bgs {
namespace protocol {

// ===================================================================

class BGSServiceOptions :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:bgs.protocol.BGSServiceOptions) */ {
 public:
  BGSServiceOptions();
  virtual ~BGSServiceOptions();

  BGSServiceOptions(const BGSServiceOptions& from);
  BGSServiceOptions(BGSServiceOptions&& from) noexcept
    : BGSServiceOptions() {
    *this = ::std::move(from);
  }

  inline BGSServiceOptions& operator=(const BGSServiceOptions& from) {
    CopyFrom(from);
    return *this;
  }
  inline BGSServiceOptions& operator=(BGSServiceOptions&& from) noexcept {
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
  static const BGSServiceOptions& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BGSServiceOptions* internal_default_instance() {
    return reinterpret_cast<const BGSServiceOptions*>(
               &_BGSServiceOptions_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(BGSServiceOptions& a, BGSServiceOptions& b) {
    a.Swap(&b);
  }
  inline void Swap(BGSServiceOptions* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline BGSServiceOptions* New() const final {
    return CreateMaybeMessage<BGSServiceOptions>(nullptr);
  }

  BGSServiceOptions* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<BGSServiceOptions>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const BGSServiceOptions& from);
  void MergeFrom(const BGSServiceOptions& from);
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
  void InternalSwap(BGSServiceOptions* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "bgs.protocol.BGSServiceOptions";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fservice_5foptions_2eproto);
    return ::descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fservice_5foptions_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDescriptorNameFieldNumber = 1,
    kShardNameFieldNumber = 5,
    kVersionFieldNumber = 4,
  };
  // optional string descriptor_name = 1;
  bool has_descriptor_name() const;
  private:
  bool _internal_has_descriptor_name() const;
  public:
  void clear_descriptor_name();
  const std::string& descriptor_name() const;
  void set_descriptor_name(const std::string& value);
  void set_descriptor_name(std::string&& value);
  void set_descriptor_name(const char* value);
  void set_descriptor_name(const char* value, size_t size);
  std::string* mutable_descriptor_name();
  std::string* release_descriptor_name();
  void set_allocated_descriptor_name(std::string* descriptor_name);
  private:
  const std::string& _internal_descriptor_name() const;
  void _internal_set_descriptor_name(const std::string& value);
  std::string* _internal_mutable_descriptor_name();
  public:

  // optional string shard_name = 5;
  bool has_shard_name() const;
  private:
  bool _internal_has_shard_name() const;
  public:
  void clear_shard_name();
  const std::string& shard_name() const;
  void set_shard_name(const std::string& value);
  void set_shard_name(std::string&& value);
  void set_shard_name(const char* value);
  void set_shard_name(const char* value, size_t size);
  std::string* mutable_shard_name();
  std::string* release_shard_name();
  void set_allocated_shard_name(std::string* shard_name);
  private:
  const std::string& _internal_shard_name() const;
  void _internal_set_shard_name(const std::string& value);
  std::string* _internal_mutable_shard_name();
  public:

  // optional uint32 version = 4;
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

  // @@protoc_insertion_point(class_scope:bgs.protocol.BGSServiceOptions)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr descriptor_name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr shard_name_;
  ::PROTOBUF_NAMESPACE_ID::uint32 version_;
  friend struct ::TableStruct_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fservice_5foptions_2eproto;
};
// -------------------------------------------------------------------

class SDKServiceOptions :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:bgs.protocol.SDKServiceOptions) */ {
 public:
  SDKServiceOptions();
  virtual ~SDKServiceOptions();

  SDKServiceOptions(const SDKServiceOptions& from);
  SDKServiceOptions(SDKServiceOptions&& from) noexcept
    : SDKServiceOptions() {
    *this = ::std::move(from);
  }

  inline SDKServiceOptions& operator=(const SDKServiceOptions& from) {
    CopyFrom(from);
    return *this;
  }
  inline SDKServiceOptions& operator=(SDKServiceOptions&& from) noexcept {
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
  static const SDKServiceOptions& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SDKServiceOptions* internal_default_instance() {
    return reinterpret_cast<const SDKServiceOptions*>(
               &_SDKServiceOptions_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(SDKServiceOptions& a, SDKServiceOptions& b) {
    a.Swap(&b);
  }
  inline void Swap(SDKServiceOptions* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SDKServiceOptions* New() const final {
    return CreateMaybeMessage<SDKServiceOptions>(nullptr);
  }

  SDKServiceOptions* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SDKServiceOptions>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SDKServiceOptions& from);
  void MergeFrom(const SDKServiceOptions& from);
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
  void InternalSwap(SDKServiceOptions* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "bgs.protocol.SDKServiceOptions";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fservice_5foptions_2eproto);
    return ::descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fservice_5foptions_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kInboundFieldNumber = 1,
    kOutboundFieldNumber = 2,
    kUseClientIdFieldNumber = 3,
  };
  // optional bool inbound = 1;
  bool has_inbound() const;
  private:
  bool _internal_has_inbound() const;
  public:
  void clear_inbound();
  bool inbound() const;
  void set_inbound(bool value);
  private:
  bool _internal_inbound() const;
  void _internal_set_inbound(bool value);
  public:

  // optional bool outbound = 2;
  bool has_outbound() const;
  private:
  bool _internal_has_outbound() const;
  public:
  void clear_outbound();
  bool outbound() const;
  void set_outbound(bool value);
  private:
  bool _internal_outbound() const;
  void _internal_set_outbound(bool value);
  public:

  // optional bool use_client_id = 3;
  bool has_use_client_id() const;
  private:
  bool _internal_has_use_client_id() const;
  public:
  void clear_use_client_id();
  bool use_client_id() const;
  void set_use_client_id(bool value);
  private:
  bool _internal_use_client_id() const;
  void _internal_set_use_client_id(bool value);
  public:

  // @@protoc_insertion_point(class_scope:bgs.protocol.SDKServiceOptions)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  bool inbound_;
  bool outbound_;
  bool use_client_id_;
  friend struct ::TableStruct_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fservice_5foptions_2eproto;
};
// ===================================================================

static const int kServiceOptionsFieldNumber = 90000;
extern ::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::google::protobuf::ServiceOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::MessageTypeTraits< ::bgs::protocol::BGSServiceOptions >, 11, false >
  service_options;
static const int kSdkServiceOptionsFieldNumber = 90001;
extern ::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::google::protobuf::ServiceOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::MessageTypeTraits< ::bgs::protocol::SDKServiceOptions >, 11, false >
  sdk_service_options;

// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// BGSServiceOptions

// optional string descriptor_name = 1;
inline bool BGSServiceOptions::_internal_has_descriptor_name() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool BGSServiceOptions::has_descriptor_name() const {
  return _internal_has_descriptor_name();
}
inline void BGSServiceOptions::clear_descriptor_name() {
  descriptor_name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& BGSServiceOptions::descriptor_name() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.BGSServiceOptions.descriptor_name)
  return _internal_descriptor_name();
}
inline void BGSServiceOptions::set_descriptor_name(const std::string& value) {
  _internal_set_descriptor_name(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.BGSServiceOptions.descriptor_name)
}
inline std::string* BGSServiceOptions::mutable_descriptor_name() {
  // @@protoc_insertion_point(field_mutable:bgs.protocol.BGSServiceOptions.descriptor_name)
  return _internal_mutable_descriptor_name();
}
inline const std::string& BGSServiceOptions::_internal_descriptor_name() const {
  return descriptor_name_.GetNoArena();
}
inline void BGSServiceOptions::_internal_set_descriptor_name(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  descriptor_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void BGSServiceOptions::set_descriptor_name(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  descriptor_name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:bgs.protocol.BGSServiceOptions.descriptor_name)
}
inline void BGSServiceOptions::set_descriptor_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  descriptor_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:bgs.protocol.BGSServiceOptions.descriptor_name)
}
inline void BGSServiceOptions::set_descriptor_name(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  descriptor_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:bgs.protocol.BGSServiceOptions.descriptor_name)
}
inline std::string* BGSServiceOptions::_internal_mutable_descriptor_name() {
  _has_bits_[0] |= 0x00000001u;
  return descriptor_name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* BGSServiceOptions::release_descriptor_name() {
  // @@protoc_insertion_point(field_release:bgs.protocol.BGSServiceOptions.descriptor_name)
  if (!_internal_has_descriptor_name()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return descriptor_name_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void BGSServiceOptions::set_allocated_descriptor_name(std::string* descriptor_name) {
  if (descriptor_name != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  descriptor_name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), descriptor_name);
  // @@protoc_insertion_point(field_set_allocated:bgs.protocol.BGSServiceOptions.descriptor_name)
}

// optional uint32 version = 4;
inline bool BGSServiceOptions::_internal_has_version() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool BGSServiceOptions::has_version() const {
  return _internal_has_version();
}
inline void BGSServiceOptions::clear_version() {
  version_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 BGSServiceOptions::_internal_version() const {
  return version_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 BGSServiceOptions::version() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.BGSServiceOptions.version)
  return _internal_version();
}
inline void BGSServiceOptions::_internal_set_version(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000004u;
  version_ = value;
}
inline void BGSServiceOptions::set_version(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_version(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.BGSServiceOptions.version)
}

// optional string shard_name = 5;
inline bool BGSServiceOptions::_internal_has_shard_name() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool BGSServiceOptions::has_shard_name() const {
  return _internal_has_shard_name();
}
inline void BGSServiceOptions::clear_shard_name() {
  shard_name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& BGSServiceOptions::shard_name() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.BGSServiceOptions.shard_name)
  return _internal_shard_name();
}
inline void BGSServiceOptions::set_shard_name(const std::string& value) {
  _internal_set_shard_name(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.BGSServiceOptions.shard_name)
}
inline std::string* BGSServiceOptions::mutable_shard_name() {
  // @@protoc_insertion_point(field_mutable:bgs.protocol.BGSServiceOptions.shard_name)
  return _internal_mutable_shard_name();
}
inline const std::string& BGSServiceOptions::_internal_shard_name() const {
  return shard_name_.GetNoArena();
}
inline void BGSServiceOptions::_internal_set_shard_name(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  shard_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void BGSServiceOptions::set_shard_name(std::string&& value) {
  _has_bits_[0] |= 0x00000002u;
  shard_name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:bgs.protocol.BGSServiceOptions.shard_name)
}
inline void BGSServiceOptions::set_shard_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000002u;
  shard_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:bgs.protocol.BGSServiceOptions.shard_name)
}
inline void BGSServiceOptions::set_shard_name(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000002u;
  shard_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:bgs.protocol.BGSServiceOptions.shard_name)
}
inline std::string* BGSServiceOptions::_internal_mutable_shard_name() {
  _has_bits_[0] |= 0x00000002u;
  return shard_name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* BGSServiceOptions::release_shard_name() {
  // @@protoc_insertion_point(field_release:bgs.protocol.BGSServiceOptions.shard_name)
  if (!_internal_has_shard_name()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return shard_name_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void BGSServiceOptions::set_allocated_shard_name(std::string* shard_name) {
  if (shard_name != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  shard_name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), shard_name);
  // @@protoc_insertion_point(field_set_allocated:bgs.protocol.BGSServiceOptions.shard_name)
}

// -------------------------------------------------------------------

// SDKServiceOptions

// optional bool inbound = 1;
inline bool SDKServiceOptions::_internal_has_inbound() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool SDKServiceOptions::has_inbound() const {
  return _internal_has_inbound();
}
inline void SDKServiceOptions::clear_inbound() {
  inbound_ = false;
  _has_bits_[0] &= ~0x00000001u;
}
inline bool SDKServiceOptions::_internal_inbound() const {
  return inbound_;
}
inline bool SDKServiceOptions::inbound() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.SDKServiceOptions.inbound)
  return _internal_inbound();
}
inline void SDKServiceOptions::_internal_set_inbound(bool value) {
  _has_bits_[0] |= 0x00000001u;
  inbound_ = value;
}
inline void SDKServiceOptions::set_inbound(bool value) {
  _internal_set_inbound(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.SDKServiceOptions.inbound)
}

// optional bool outbound = 2;
inline bool SDKServiceOptions::_internal_has_outbound() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool SDKServiceOptions::has_outbound() const {
  return _internal_has_outbound();
}
inline void SDKServiceOptions::clear_outbound() {
  outbound_ = false;
  _has_bits_[0] &= ~0x00000002u;
}
inline bool SDKServiceOptions::_internal_outbound() const {
  return outbound_;
}
inline bool SDKServiceOptions::outbound() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.SDKServiceOptions.outbound)
  return _internal_outbound();
}
inline void SDKServiceOptions::_internal_set_outbound(bool value) {
  _has_bits_[0] |= 0x00000002u;
  outbound_ = value;
}
inline void SDKServiceOptions::set_outbound(bool value) {
  _internal_set_outbound(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.SDKServiceOptions.outbound)
}

// optional bool use_client_id = 3;
inline bool SDKServiceOptions::_internal_has_use_client_id() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool SDKServiceOptions::has_use_client_id() const {
  return _internal_has_use_client_id();
}
inline void SDKServiceOptions::clear_use_client_id() {
  use_client_id_ = false;
  _has_bits_[0] &= ~0x00000004u;
}
inline bool SDKServiceOptions::_internal_use_client_id() const {
  return use_client_id_;
}
inline bool SDKServiceOptions::use_client_id() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.SDKServiceOptions.use_client_id)
  return _internal_use_client_id();
}
inline void SDKServiceOptions::_internal_set_use_client_id(bool value) {
  _has_bits_[0] |= 0x00000004u;
  use_client_id_ = value;
}
inline void SDKServiceOptions::set_use_client_id(bool value) {
  _internal_set_use_client_id(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.SDKServiceOptions.use_client_id)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fservice_5foptions_2eproto
