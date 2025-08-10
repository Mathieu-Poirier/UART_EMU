class device_driver {
    public:
        virtual ~device_driver() = default;

        virtual void init() = 0;
        virtual void close() = 0;
};