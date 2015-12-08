# This podspec is for release

Pod::Spec.new do |s|
  s.name = 'TuisongbaoRealtimeEngine'
  s.version = '2.1.2'
  s.summary = 'Help you develop realtime app much easier.'
  s.description = <<-DESC
                  Help you develop realtime app much easier with pub/sub, chat patterns.
                  DESC
  s.homepage = 'http://www.tuisongbao.com'
  s.documentation_url = 'http://www.tuisongbao.com/docs/engineAPI/clientIOS/'
  s.license = 'MIT'
  s.authors = { 'Aaron Wang' => 'inetfuture@gmail.com' }
  s.platform = :ios, '7.0'
  s.source = { :git => 'https://github.com/tuisongbao/realtime-engine-client-ios.git', :tag => "#{s.version}" }
  s.preserve_paths = 'TuisongbaoRealtimeEngine.framework'
  s.vendored_frameworks = 'TuisongbaoRealtimeEngine.framework'
  s.public_header_files = 'TuisongbaoRealtimeEngine.framework/Headers/TuisongbaoRealtimeEngine.h'
  s.resources = 'TuisongbaoRealtimeEngine.framework/TuisongbaoRealtimeEngine.plist'
  s.libraries = 'icucore'
  s.requires_arc = true

  s.dependency 'Qiniu', '~> 7.0'
end
